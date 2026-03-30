import threading
import time
import random

from printDoc import printDoc
from printList import printList

class Assignment1:
    # Simulation Initialisation parameters
    NUM_MACHINES = 2         # Number of machines that issue print requests
    NUM_PRINTERS = 1         # Number of printers in the system (max queue size = NUM_PRINTERS)
    SIMULATION_TIME = 5      # Total simulation duration in seconds
    MAX_PRINTER_SLEEP = 1    # Maximum sleep time for printers (simulate printing time)
    MAX_MACHINE_SLEEP = 1    # Maximum sleep time for machines (simulate idle time)

    """
    Main class for the print queue simulation (Producer-Consumer model)
    Machines act as producers (send print requests)
    Printers act as consumers (process print requests)
    """
    def __init__(self):
        self.sim_active = True                  # Flag to control simulation lifecycle
        self.print_list = printList()           # Original print queue (unchanged)
        self.mThreads = []                      # List to store machine threads
        self.pThreads = []                      # List to store printer threads
        
        # Core components for thread synchronization (Task2 key logic)
        self.lock = threading.Lock()                          # Mutex lock for queue operations
        self.queue_not_full = threading.Condition(self.lock)  # Condition: queue is not full (for machines)
        self.queue_not_empty = threading.Condition(self.lock) # Condition: queue is not empty (for printers)
        self.queue_size = 0                                  # Track queue size locally (without modifying printList)

    def startSimulation(self):
        """
        Initialize and start all machine/printer threads, 
        control simulation duration, and clean up threads
        """
        print("==== Starting Thread Creation ====")
        # Create machine threads
        for machine_id in range(1, self.NUM_MACHINES + 1):
            machine = self.machineThread(machine_id, self)
            self.mThreads.append(machine)
            print(f"✅ Machine Thread {machine_id} Created")
        
        # Create printer threads
        for printer_id in range(1, self.NUM_PRINTERS + 1):
            printer = self.printerThread(printer_id, self)
            self.pThreads.append(printer)
            print(f"✅ Printer Thread {printer_id} Created")
        
        print("==== Starting All Threads ====")
        # Start all machine threads
        for m_thread in self.mThreads:
            m_thread.start()
            print(f"🚀 Machine Thread {m_thread.machineID} Started")
        # Start all printer threads
        for p_thread in self.pThreads:
            p_thread.start()
            print(f"🚀 Printer Thread {p_thread.printerID} Started")

        # Run simulation for specified duration
        print(f"==== Simulation Running for {self.SIMULATION_TIME} Seconds ====")
        time.sleep(self.SIMULATION_TIME)

        # Terminate simulation
        self.sim_active = False
        print("==== Simulation Time Expired, Waiting for Threads to Finish ====")
        
        # Wake up all waiting threads to avoid deadlock
        with self.lock:
            self.queue_not_full.notify_all()
            self.queue_not_empty.notify_all()
        
        # Wait for all printer threads to complete remaining tasks
        for p_thread in self.pThreads:
            p_thread.join()
            print(f"🔚 Printer Thread {p_thread.printerID} Terminated")
        
        # Print final queue status for debugging
        print("Final Queue Status:")
        self.print_list.queuePrintAll()
        print("Simulation finished! (Task2 - No Overwrite)")

    # ===================== Printer Thread Class =====================
    class printerThread(threading.Thread):
        """
        Printer thread class (Consumer)
        Processes print requests from the queue
        """
        def __init__(self, printerID, outer):
            threading.Thread.__init__(self)
            self.printerID = printerID          # Unique ID for printer
            self.outer = outer                  # Reference to parent Assignment1 instance

        def run(self):
            """
            Core logic for printer thread:
            1. Sleep randomly (simulate printing time)
            2. Wait for queue to have requests (if empty)
            3. Process print request
            4. Notify waiting machines (queue has space now)
            """
            while self.outer.sim_active:
                self.printerSleep()
                with self.outer.queue_not_empty:
                    # Wait if queue is empty (with timeout to avoid permanent deadlock)
                    while self.outer.queue_size == 0 and self.outer.sim_active:
                        print(f"Printer ID: {self.printerID} : no requests, waiting...")
                        self.outer.queue_not_empty.wait(timeout=5)
                    # Exit loop if simulation is terminated
                    if not self.outer.sim_active:
                        break
                    # Process the print request
                    self.printDox(self.printerID)
                    # Decrease queue size after processing
                    self.outer.queue_size -= 1
                    # Notify machines: queue has free space
                    self.outer.queue_not_full.notify()

        def printerSleep(self):
            """Simulate printer processing time with random sleep"""
            sleepSeconds = random.randint(1, self.outer.MAX_PRINTER_SLEEP)
            time.sleep(sleepSeconds)

        def printDox(self, printerID):
            """Call original queue print method to process the first request"""
            print(f"Printer ID: {printerID} : now available")
            self.outer.print_list.queuePrint(printerID)

    # ===================== Machine Thread Class =====================
    class machineThread(threading.Thread):
        """
        Machine thread class (Producer)
        Sends print requests to the queue
        """
        def __init__(self, machineID, outer):
            threading.Thread.__init__(self)
            self.machineID = machineID          # Unique ID for machine
            self.outer = outer                  # Reference to parent Assignment1 instance

        def run(self):
            """
            Core logic for machine thread:
            1. Sleep randomly (simulate idle time)
            2. Wait for queue to have space (if full)
            3. Send print request
            4. Notify waiting printers (new request in queue)
            """
            while self.outer.sim_active:
                self.machineSleep()
                with self.outer.queue_not_full:
                    # Wait if queue is full (with timeout to avoid permanent deadlock)
                    while self.outer.queue_size >= self.outer.NUM_PRINTERS and self.outer.sim_active:
                        print(f"!!!!!!Attention: Queue Full, Machine {self.machineID} waiting!!!!!!")
                        self.outer.queue_not_full.wait(timeout=5)
                    # Exit loop if simulation is terminated
                    if not self.outer.sim_active:
                        break
                    # Send print request to queue
                    self.printRequest(self.machineID)
                    # Increase queue size after sending request
                    self.outer.queue_size += 1
                    # Notify printers: new request in queue
                    self.outer.queue_not_empty.notify()

        def machineSleep(self):
            """Simulate machine idle time with random sleep"""
            sleepSeconds = random.randint(1, self.outer.MAX_MACHINE_SLEEP)
            time.sleep(sleepSeconds)

        def printRequest(self, machine_id):
            """Create print document and call original queue insert method"""
            print(f"Machine {machine_id} Sent a print request")
            doc = printDoc(f"My name is machine {machine_id}", machine_id)
            self.outer.print_list.queueInsert(doc)
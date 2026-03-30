import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class LottoDraw{
    private static final int MAX_NUM=39;
    private static final int MIN_NUM=1;
    private static final int NUM_PER_TICKET=6;
    private static final int WINNER_NUM_COUNT=6;
    private static final int TOTAL_TICKET=100;
    private static final double TICKET_PRICE=10;

    //the rule of the ticket

    private double getPrice(int count){
        double price=0.00;
        switch(count){

            case 0:
            case 1:
                price=0.00;
                break;
            case 2:
                price=10.00;
                break;
            case 3:
                price=100.00;
                break;
            case 4:
                price=1000.00;
                break;
            case 5:
                price=10000.00;
                break;
            case 6:
                price=1000000.00;
                break;
            default:
                price=0.00;
                break;


        }
        return price;
    }

        
    
    

    //add all the number 0-39 to the number pool

    private StrLinkedList initNumberPool(){

        StrLinkedList pool=new StrLinkedList();

        for (int i=MIN_NUM;i<MAX_NUM;i++){

            pool.add(String.Valueof(i));

        }
        return pool;
    }
//choose n numbers from the pool randomly


private StrLinkedList chooseRandomNum(StrLinkedList source,int n){


    if(n>StrLinkedList.getLength()){

        throw new IllegalArgumentException("The selecting numbers can not beyond the length of the linked list.");

    }

    StrLinkedList result = new StrLinkedList();
    Random random = new Random();
    //copy the source libnked list to avoid change the source
    StrLinkedList copy=new StrLinkedList();
    for(int i=0;i<source.getLength() ;i++){

        copy.add(source.getValueAt(i));
    }
    for (int i = 0; i < n; i++) {
            int randomIndex = random.nextInt(tempPool.getLength());
            String num = tempPool.getValueAt(randomIndex);
            result.add(num);
            tempPool.remove(num); // 

        }
        return result;


}

//generate tickets

private List<StrLinkedList> generateTickets(StrLinkedList pool,int count){

    List<StrLinkedList> tickets=new ArrayList<>();
    for(int i=0;i<count;i++){
        StrLinkedList ticket=chooseRandomNum(pool,NUM_PER_TICKET);
        tickets.add(ticket);
    }

    return tickets;
}
//calculate the match numbers
private int countMatches(StrLinkedList ticket, StrLinkedList winningNumbers) {
        int matchCount = 0;
        for (int i = 0; i < ticket.getLength(); i++) {
            String num = ticket.getValueAt(i);
            if (winningNumbers.hasValue(num)) {
                matchCount++;
            }
        }
        return matchCount;
    }

//calculate the whole price
private double calculateTotalPrize(List<StrLinkedList> tickets, StrLinkedList winningNumbers) {
        double totalPrize = 0.0;
        for (StrLinkedList ticket : tickets) {
            int matches = countMatches(ticket, winningNumbers);
            totalPrize += getPrize(matches);
        }
        return totalPrize;
    }


//calculate the whole profit

private void printResults(double totalPrize){

    double totalSales=TOTAL_TICKET*TICKET_PRICE;
    double profit =totalSales-totalPrize;

    System.out.println("----The result of the tickets------");
    System.out.pritnln("Total sales:$%.2f%n",totalSales);
    System.out.println("Total price:$%.2f%n",totalPrize);
    System.out.println("Profit: $%.2f%n", profit);
    System.out.println("==========================");

}


public static void main(String[] args) {
        LottoDraw lotto = new LottoDraw();

       
        StrLinkedList numberPool = lotto.initNumberPool();
        System.out.println("Init number pool:");
        numberPool.print();

        
        StrLinkedList winningNumbers = lotto.chooseRandomNumbers(numberPool, WINNING_NUMBERS_COUNT);
        System.out.println("\nThe winnner numbers:");
        winningNumbers.print();

       
        List<StrLinkedList> tickets = lotto.generateTickets(numberPool, TOTAL_TICKETS);
        System.out.println("\nIt generates " + TOTAL_TICKETS + " tickets");

       
        double totalPrize = lotto.calculateTotalPrize(tickets, winningNumbers);

     
        lotto.printResults(totalPrize);
    }



    StrLinkedList possibleNum
}
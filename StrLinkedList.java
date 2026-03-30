

public class StrLinkedList{


    private Node head;

    private static class Node{
        String value;
        Node next;
        public Node(String value){
            this.value=value;
            next=null;
        }
    }

    public StrLinkedList(){
        head=null;

    }

    public boolean isEmpty(){
        return head==null;

    }

    public int getLength(){
        int count=0;
        Node current =head;
        
        while(current!=null){
            current=current.next;
            count++;
        }
        return count;

    }

    public boolean hasValue(String s){
        Node current=head;
        while(current!=null){
            if(current.value.equals(s)){
                return true;
            }
            current=current.next;
        }
        return false;

    }

    public String getValueAt(int i){
        Node current=head;
        if(i<1||isEmpty()){
            return null;
        }
        int pos=1;
        while(current!=null){
            if(pos==i){
                return current.value;
            }
            pos++;
            current=current.next;
        }
        return null;
    }

    public void add(String s){
        Node newNode=new Node(s);
        newNode.next=head;
        head=newNode;
        
    }

    public void remove(String s){
        Node current=head;
        if(isEmpty()){
            return;
        }
        if(current.value.equals(s)){
            current=current.next;

        }
        while (current.next != null && !current.next.value.equals(s)) {
            current = current.next;
        }
        if (current.next != null) {
            current.next = current.next.next;
        }
    }

    public void print() {
        Node current = head;
        while (current != null) {
            System.out.print(current.value + "->");
            current = current.next;
        }
        
        System.out.println();
    }
     public static void main(String[] args) {
       
        StrLinkedList list = new StrLinkedList();

        
        System.out.println("The linked list is empty or not：" + list.isEmpty()); // true

       
        list.add("A");
        list.add("B");
        list.add("C");
        list.add("D");
        list.add("E");

        
        System.out.print("The content of the linked list：");
        list.print(); // E->D->C->B->A->

        
        System.out.println("The length of the linked list：" + list.getLength()); // 5

       
        System.out.println("whether c in the linked list：" + list.hasValue("C")); // true
        System.out.println("whether f in linked list：" + list.hasValue("F")); // false

        
        System.out.println("The value of the index 2：" + list.getValueAt(2)); // C
        System.out.println("The value of the index 10：" + list.getValueAt(10)); // null

       
        list.remove("C");
        System.out.print("After deletion of c：");
        list.print(); // E->D->B->A->

       
        list.remove("F");
        System.out.print("After deletion  of unexit f：");
        list.print(); // E->D->B->A->

        System.out.println("The linked list is empty or not：" + list.isEmpty()); // false
    }
}








 
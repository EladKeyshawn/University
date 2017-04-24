package lesson1;

public class LinkedList {
    Node head = null;

    LinkedList() {

    }

    LinkedList(Node node) {
        head = node;
    }

    public boolean isEmpty(){
        return head == null;
    }

    Node get(int data){
        Node runner = head;
        while(runner.next != null) {
            if (data == runner.getData())
                return runner;
            runner = runner.next;
        }

        return null;
    }

    Node getTail() {
        Node runner = head;

        if(runner.next == null && !isEmpty())
            return head;

        while(runner.next != null) {
            runner = runner.next;
        }
        return runner;
    }

    void insert(int data) {
        if(head != null) {
            Node tail = getTail();
            tail.next = new Node(data);
        } else {
            head = new Node(data);
        }
    }


    void print(){
        Node printer = head;
        while (printer != null){
            System.out.print(printer.getData());

            if (printer.next != null)
                System.out.print(" -> ");

            printer = printer.next;
        }
        System.out.println();

    }

    Node checkCircle(){
        Node r1 = head;
        Node r2 = head;

        while (r2.next.next != null) {
            r1 = r1.next;
            r2 = r2.next.next;

            if (r1 == r2)
                return r1;
        }

        return null;

    }

    Node getCircleStart(){
        Node hare = checkCircle();
        if (hare != null) {
            // start loop start detection
            Node turtle = head;

            while(turtle != hare) {
                turtle = turtle.next;
                hare = hare.next;
            }
            return hare;
        } else {
            // no loop engine down
            return null;
        }
    }
}


class Node {
    private int data = 0;
    Node next = null;

    public Node(int data) {
        this.data = data;
    }

    public int getData(){
        return data;
    }
}

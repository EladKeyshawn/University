package lesson1;


public class Test {

    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        list.insert(3);
        list.insert(1);
        list.insert(8);
        list.insert(9);
        list.insert(2);
        list.insert(7);

//        System.out.print(list.getTail().getData());
        list.print();

        list.get(2).next = list.get(8);

        Node inters =list.checkCircle();
        Node loopStart = list.getCircleStart();
//        if (inters != null) {
//            System.out.println(inters.getData());
//        } else {
//            System.out.println(false);
//        }

        if (loopStart != null) {
            System.out.println("loop start at: " + loopStart.getData());
        } else {
            System.out.println("No circle");
        }
    }
}

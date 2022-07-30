package dsalgo.java.linkedlist;

import java.util.ArrayList;
import java.util.Arrays;

class Node<T>{
    private T data;
    Node<T> next;

    Node(T data){
        this.data = data;
        this.next = null;
    }

    public T getData() {
        return data;
    }
}

public class LinkedList<T> {
    Node head;

    LinkedList(){
        this.head = null;
    }
    public void addAtEnd(T data) {
        if(head == null){
            head = new Node<T>(data);
            return;
        }

        Node<T> temp = head;
        while(temp.next != null){
            temp = temp.next;
        }
        temp.next = new Node<T>(data);
        return;
    }

    public void addAtBeginning(T data){
        Node<T> n1 = new Node<T>(data);
        n1.next = head;
        head = n1;
    }

    public void addAtMiddle(T data){

    }




    public void display(){
        System.out.println("In Display");
        Node<T> temp = head;
        while(temp!= null){
            System.out.print(temp.getData() + " ");
            temp = temp.next;
        }
        System.out.println();
    }





    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        ArrayList<Integer> arr = new ArrayList<Integer>( Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10));

        for(Integer item : arr){
            list.addAtEnd(item);
        }
        list.display();

        for(Integer item : arr){
            list.addAtBeginning(item + 100);
        }

        list.display();

    }


}

package dsalgo.java.array;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class ReverseArray {
//    public static void swap(int a[], int b[]){
//        int c = a;
//        a = b;
//        b  = c;
//    }
    public static ArrayList<Integer> reverseArray(ArrayList<Integer> arr){
        int n = arr.size();
        for(int i = 0;  i < arr.size()/2; i++){
            int c = arr.get(i);
            arr.set(i, arr.get(n - 1 - i));
            arr.set(n - 1 - i, c);

            //  This could be done in a single line
            // Collections.swap(arr, i, arr.size() - 1 - i);

        }
        return arr;
    }
    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<Integer>( Arrays.asList(1, 2, 3, 4, 5));

        ArrayList<Integer> output = reverseArray(arr);

        for(int i : arr){
            System.out.print(i + " ");
        }

    }
}

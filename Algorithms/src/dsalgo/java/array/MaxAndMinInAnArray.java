package dsalgo.java.array;

import java.util.ArrayList;
import java.util.Arrays;

public class MaxAndMinInAnArray {
    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<>(Arrays.asList(123, 34, 312, 532, 324, 1234, 454,342342));

        System.out.println(findMax(arr));
        System.out.println(findMin(arr));

    }

    private static int findMin(ArrayList<Integer> arr) {
        int min = arr.get(0);

        for(int item : arr){
            if(item < min){
                min = item;
            }
        }
        return min;
    }

    private static int findMax(ArrayList<Integer> arr) {
        int max = arr.get(0);
        for(int i = 0; i < arr.size(); i++){
            if(max < arr.get(i)) {
                max = arr.get(i);
            }
        }
        return max;
    }
}

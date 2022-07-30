package dsalgo.java.array.quickselect;

import java.util.*;

public class KthMaxMinElement {
    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<>(Arrays.asList(7, 9, 4, 8, 3, 6, 2, 1, 5));
        int k = 3;
//        kthMaxAndMin1(arr, k);
//        System.out.println(kthMaxAndMin2(arr, k));
        System.out.println(kthMinElement_quickSelect(arr, 0, arr.size() - 1, k - 1));
    }

    private static void kthMaxAndMin1(ArrayList<Integer> arr, int k) {
        // Time Complexity : The worst-case time complexity of this approach will be O(n.log(n)), where n is the size of the input.
        Collections.sort(arr);
        for(int element : arr){
            System.out.print(element + " ");
        }

        System.out.println();
        int n = arr.size();
        System.out.println("Kth Min Element is " + arr.get(k - 1));
        System.out.println("Kth Max Element is " + arr.get(n - k));
    }
    private static int kthMaxAndMin2(ArrayList<Integer> arr, int k) {
        int n = arr.size();
        // This is Kth Min
        /*
        * We can easily solve this problem in O(n.log(k)) time by using a max-heap, where n is the size of the input.
        * The idea is to simply construct a max-heap of size k and insert the first k elements of array [0…k-1] into the max-heap.
        * Then for each of the remaining array elements [k…n-1], if that element is less than the heap’s root, replace the root with the current element.
        * Repeat this process till the array is exhausted.
        * Now, we will be left with k smallest array elements in the max-heap, and k'th smallest element will reside at the root of the max-heap.
        *
        * */
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        pq.addAll(arr.subList(0, k));

        for(int i = k; i < n; i++) {
            if (arr.get(i) < pq.peek()) {
                pq.poll();
                pq.add(arr.get(i));
            }

        }
            return pq.peek();
    }
    private static void swap(ArrayList<Integer> arr, int i, int j){
        int c = arr.get(i);
        arr.set(i, arr.get(j));
        arr.set(j, c);
    }
    private static int partition(ArrayList<Integer> arr, int pivot){
//        System.out.println(pivot);
        int i = 0, j = 0;
        int n = arr.size();

        while (i < n) {
            if (arr.get(i) > pivot) {
                i++;
            }
            else{
                swap(arr, i, j);
                i++;
                j++;

            }
//            System.out.println("i " + i);
//            System.out.println("j " + j);

//            for(int item : arr){
//                System.out.print(item + " ");
//            }
//            System.out.println();

        }

        return j - 1;
    }
    private static int kthMinElement_quickSelect(ArrayList<Integer> arr, int start, int end, int k){
        int pivot = arr.get(end);
        int pivot_index = partition(arr, pivot);

        if(k > pivot_index){
            return kthMinElement_quickSelect(arr, pivot_index + 1, arr.size() - 1, k);

        }
        else if(k < pivot_index){
            return kthMinElement_quickSelect(arr, 0, pivot_index - 1, k);

        }
        else{
                return arr.get(pivot_index);
        }

    }


}

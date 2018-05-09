// Author: Sunaina Pai
// License: MIT

import java.util.Arrays;

public class A01InsertionSort {

    public static void insertionSort(int[] A) {
        for (int j = 1; j < A.length; j++) {
            // Insert A[j] in sorted sequence A[0..j-1].
            int key = A[j];
            int i = j - 1;

            while (i >= 0 && A[i] > key) {
                A[i + 1] = A[i];
                i--;
            }

            A[i + 1] = key;
        }
    }

    public static void main(String[] args) {
        int A[] = {5, 4, 1, 3, 2, 6};
        insertionSort(A);
        System.out.println(Arrays.toString(A));
    }
}

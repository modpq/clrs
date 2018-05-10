// Author: Sunaina Pai
// License: MIT

import java.util.Arrays;

public class A02MergeSort {

    public static void merge(int[] A, int p, int q, int r) {

        int[] L = Arrays.copyOfRange(A, p, q + 1);     // L = A[p..q]
        int[] R = Arrays.copyOfRange(A, q + 1, r + 1); // R = A[q+1..r]
        int n1 = L.length; // n1 = q - p + 1
        int n2 = R.length; // n2 = r - q

        int i = 0;
        int j = 0;
        int k = p;

        while (i < n1 && j < n2) {
             if (L[i] <= R[j]) {
                 A[k] = L[i];
                 i++;
             } else {
                 A[k] = R[j];
                 j++;
             }
             k++;
        }

        while (i < n1) {
            A[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            A[k] = R[j];
            j++;
            k++;
        }

    }

    public static void mergeSort(int[] A, int p, int r) {
        if (p < r) {
            int q = (p + r) / 2;
            mergeSort(A, p, q);
            mergeSort(A, q + 1, r);
            merge(A, p, q, r);
        }
    }

    public static void main(String[] args) {
        int A[] = {5, 4, 1, 3, 2, 6};
        mergeSort(A, 0, A.length - 1);
        System.out.println(Arrays.toString(A));
    }
}

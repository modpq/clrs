// Author: Sunaina Pai
// License: MIT

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertArrayEquals;

public class A02MergeSortTest {

    @Test
    public void testMergeTypical() {
        int[] A = {1, 7, 9, 2, 6, 8};
        A02MergeSort.merge(A, 0, 2, A.length - 1);
        assertArrayEquals(A, new int[] {1, 2, 6, 7, 8, 9});
    }

    @Test
    public void testMergeTwoItems() {
        int[] A = {1, 7, 9, 2, 6, 8};
        A02MergeSort.merge(A, 2, 2, 3);
        assertArrayEquals(A, new int[] {1, 7, 2, 9, 6, 8});
    }

    @Test
    public void testMergeOneItem() {
        int[] A = {1, 7, 9, 2, 6, 8};
        A02MergeSort.merge(A, 2, 2, 2);
        assertArrayEquals(A, new int[] {1, 7, 9, 2, 6, 8});
    }

    @Test
    public void testMergeSortTypical() {
        int[] A = {1, 7, 9, 2, 6, 8};
        A02MergeSort.mergeSort(A, 0, A.length - 1);
        assertArrayEquals(A, new int[] {1, 2, 6, 7, 8, 9});
    }

    @Test
    public void testMergeSortTwoItems() {
        int[] A = {1, 7, 9, 2, 6, 8};
        A02MergeSort.mergeSort(A, 2, 3);
        assertArrayEquals(A, new int[] {1, 7, 2, 9, 6, 8});
    }

    @Test
    public void testMergeSortOneItem() {
        int[] A = {1, 7, 9, 2, 6, 8};
        A02MergeSort.mergeSort(A, 2, 2);
        assertArrayEquals(A, new int[] {1, 7, 9, 2, 6, 8});
    }
}

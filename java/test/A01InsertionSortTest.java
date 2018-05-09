// Author: Sunaina Pai
// License: MIT

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertArrayEquals;

public class A01InsertionSortTest {

    @Test
    public void testInsertionSortTypical() {
        int[] A = {1, 7, 9, 2, 6, 8};
        A01InsertionSort.insertionSort(A);
        assertArrayEquals(A, new int[] {1, 2, 6, 7, 8, 9});
    }

    @Test
    public void testInsertionSortEmpty() {
        int[] A = {};
        A01InsertionSort.insertionSort(A);
        assertArrayEquals(A, new int[] {});
    }

    @Test
    public void testInsertionSortOne() {
        int[] A = {5};
        A01InsertionSort.insertionSort(A);
        assertArrayEquals(A, new int[] {5});
    }

    @Test
    public void testInsertionSortSorted() {
        int[] A = {1, 2, 6, 7, 8, 9};
        A01InsertionSort.insertionSort(A);
        assertArrayEquals(A, new int[] {1, 2, 6, 7, 8, 9});
    }

    @Test
    public void testInsertionSortReverseSorted() {
        int[] A = {9, 8, 7, 6, 2, 1};
        A01InsertionSort.insertionSort(A);
        assertArrayEquals(A, new int[] {1, 2, 6, 7, 8, 9});
    }
}

#!/usr/bin/env python3

# Author: Sunaina Pai
# License: MIT


import unittest
from a03_max_subarray import find_max_crossing_subarray, find_max_subarray


class MaxSubarrayTest(unittest.TestCase):
    def test_find_max_crossing_subarray_all_positives(self):
        A = [1, 7, 9, 2, 6, 8]
        result = find_max_crossing_subarray(A, 0, 2, len(A) - 1)
        self.assertEqual(result, (0, 5, 33))

    def test_find_max_crossing_subarray_negatives(self):
        A = [1, -7, 9, 2, -6, 8]
        result = find_max_crossing_subarray(A, 0, 2, len(A) - 1)
        self.assertEqual(result, (2, 5, 13))

    def test_find_max_crossing_subarray_three_items(self):
        A = [1, -7, 9, 2, -6, 8]
        result = find_max_crossing_subarray(A, 2, 3, 4)
        self.assertEqual(result, (2, 4, 5))

    def test_find_max_crossing_subarray_two_items(self):
        A = [1, -7, 9, 2, -6, 8]
        result = find_max_crossing_subarray(A, 2, 2, 3)
        self.assertEqual(result, (2, 3, 11))

    def test_find_max_crossing_subarray_one_item(self):
        A = [1, -7, 9, 2, -6, 8]
        with self.assertRaises(AssertionError):
            find_max_crossing_subarray(A, 2, 2, 2)

    def test_find_max_crossing_subarray_one_item_list(self):
        A = [1]
        with self.assertRaises(AssertionError):
            find_max_crossing_subarray(A, 0, 0, 0)

    def test_find_max_subarray_all_positives(self):
        A = [1, 7, 9, 2, 6, 8]
        result = find_max_subarray(A, 0, len(A) - 1)
        self.assertEqual(result, (0, 5, 33))

    def test_find_max_subarray_negatives(self):
        A = [1, -7, 9, 2, -6, 8]
        result = find_max_subarray(A, 0, len(A) - 1)
        self.assertEqual(result, (2, 5, 13))

    def test_find_max_subarray_three_items(self):
        A = [1, -7, 9, 2, -6, 8]
        result = find_max_subarray(A, 2, 4)
        self.assertEqual(result, (2, 3, 11))

    def test_find_max_subarray_two_items(self):
        A = [1, -7, 9, 2, -6, 8]
        result = find_max_subarray(A, 3, 4)
        self.assertEqual(result, (3, 3, 2))

    def test_find_max_subarray_one_item(self):
        A = [1, -7, 9, 2, -6, 8]
        result = find_max_subarray(A, 2, 2)
        self.assertEqual(result, (2, 2, 9))

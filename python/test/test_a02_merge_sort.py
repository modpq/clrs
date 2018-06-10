#!/usr/bin/env python3

# Author: Sunaina Pai
# License: MIT


import unittest
from a02_merge_sort import merge, merge_sort


class MergeSortTest(unittest.TestCase):
    def test_merge_typical(self):
        A = [1, 7, 9, 2, 6, 8]
        merge(A, 0, 2, len(A) - 1)
        self.assertEqual(A, [1, 2, 6, 7, 8, 9])

    def test_merge_two_items(self):
        A = [1, 7, 9, 2, 6, 8]
        merge(A, 2, 2, 3)
        self.assertEqual(A, [1, 7, 2, 9, 6, 8])

    def test_merge_one_item(self):
        A = [1, 7, 9, 2, 6, 8]
        merge(A, 2, 2, 2)
        self.assertEqual(A, [1, 7, 9, 2, 6, 8])

    def test_merge_sort_typical(self):
        A = [1, 7, 9, 2, 6, 8]
        merge_sort(A, 0, len(A) - 1)
        self.assertEqual(A, [1, 2, 6, 7, 8, 9])

    def test_merge_sort_two_items(self):
        A = [1, 7, 9, 2, 6, 8]
        merge_sort(A, 2, 3)
        self.assertEqual(A, [1, 7, 2, 9, 6, 8])

    def test_merge_sort_one_item(self):
        A = [1, 7, 9, 2, 6, 8]
        merge_sort(A, 2, 2)
        self.assertEqual(A, [1, 7, 9, 2, 6, 8])

#!/usr/bin/env python3

# Author: Sunaina Pai
# License: MIT


import unittest
from a01_insertion_sort import insertion_sort


class InsertionSortTest(unittest.TestCase):
    def test_insertion_sort_typical(self):
        A = [1, 7, 9, 2, 6, 8]
        insertion_sort(A)
        self.assertEqual(A, [1, 2, 6, 7, 8, 9])

    def test_insertion_sort_empty(self):
        A = []
        insertion_sort(A)
        self.assertEqual(A, [])

    def test_insertion_sort_one(self):
        A = [5]
        insertion_sort(A)
        self.assertEqual(A, [5])

    def test_insertion_sort_sorted(self):
        A = [1, 2, 6, 7, 8, 9]
        insertion_sort(A)
        self.assertEqual(A, [1, 2, 6, 7, 8, 9])

    def test_insertion_sort_reverse_sorted(self):
        A = [9, 8, 7, 6, 2, 1]
        insertion_sort(A)
        self.assertEqual(A, [1, 2, 6, 7, 8, 9])

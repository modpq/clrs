#!/usr/bin/env python3

# Author: Sunaina Pai
# License: MIT


def insertion_sort(A):
    for j in range(1, len(A)):
        # Insert A[j] into the sorted sequence A[0..j-1].
        key = A[j]
        i = j - 1

        while i >= 0 and A[i] > key:
            A[i + 1] = A[i]
            i -= 1

        A[i + 1] = key


if __name__ == '__main__':
    A = [5, 4, 1, 3, 2, 6]
    insertion_sort(A)
    print(A)

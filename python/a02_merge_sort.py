#!/usr/bin/env python3

# Author: Sunaina Pai
# License: MIT


def merge(A, p, q, r):
    L = A[p:q+1]   # L = A[p..q]
    R = A[q+1:r+1] # R = A[q+1..r]
    n1 = len(L)    # n1 = q - p + 1
    n2 = len(R)    # n2 = r - q

    i = 0
    j = 0
    k = p

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            A[k] = L[i]
            i = i + 1
        else:
            A[k] = R[j]
            j = j + 1
        k = k + 1

    while i < n1:
        A[k] = L[i]
        i = i + 1
        k = k + 1

    while j < n2:
        A[k] = R[j]
        j = j + 1
        k = k + 1


def merge_sort(A, p, r):
    if p < r:
        q = (p + r) // 2
        merge_sort(A, p, q)
        merge_sort(A, q + 1, r)
        merge(A, p, q, r)


if __name__ == '__main__':
    A = [5, 4, 1, 3, 2, 6]
    merge_sort(A, 0, len(A) - 1)
    print(A)

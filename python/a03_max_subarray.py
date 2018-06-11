#!/usr/bin/env python3

# Author: Sunaina Pai
# License: MIT


def find_max_crossing_subarray(A, low, mid, high):
    assert low <= mid < high

    sum_ = 0

    for i in range(mid, low - 1, -1):
        sum_ += A[i]
        if i == mid or sum_ > left_sum:
            left_sum = sum_
            max_left = i

    sum_ = 0

    for j in range(mid + 1, high + 1):
        sum_ += A[j]
        if j == mid + 1 or sum_ > right_sum:
            right_sum = sum_
            max_right = j

    return max_left, max_right, left_sum + right_sum


def find_max_subarray(A, low, high):
    if low == high:
        return low, high, A[low]

    mid = (low + high) // 2

    left_low, left_high, left_sum = (
            find_max_subarray(A, low, mid))

    right_low, right_high, right_sum = (
            find_max_subarray(A, mid + 1, high))

    cross_low, cross_high, cross_sum = (
            find_max_crossing_subarray(A, low, mid, high))

    if left_sum >= right_sum and left_sum >= cross_sum:
        return left_low, left_high, left_sum

    if right_sum >= left_sum and right_sum >= cross_sum:
        return right_low, right_high, right_sum

    return cross_low, cross_high, cross_sum


if __name__ == '__main__':
    A = [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7]
    low, high, max_sum = find_max_subarray(A, 0, len(A) - 1)
    print(low, high, max_sum)

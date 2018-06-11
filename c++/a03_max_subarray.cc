// Author: Susam Pal
// License: MIT


#include <iostream>
#include <vector>
#include <tuple>
#include <stdexcept>


std::tuple<std::size_t, std::size_t, int>
find_max_crossing_subarray(std::vector<int>& A,std::size_t low,
                           std::size_t mid, std::size_t high)
{
    if (!(low <= mid && mid < high)) {
        throw std::invalid_argument("required low <= mid < high");
    }

    std::size_t max_left;
    auto left_sum = 0;
    auto sum = 0;

    for (auto i = mid; i >= low; i--) {
        sum += A[i];
        if (i == mid || sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }

        if (i == 0)
            break;
    }

    std::size_t max_right;
    auto right_sum = 0;
    sum = 0;

    for (auto j = mid + 1; j <= high; j++) {
        sum += A[j];
        if (j == mid + 1 || sum > right_sum) {
            right_sum = sum;
            max_right = j;
        }
    }

    return std::make_tuple(max_left, max_right, left_sum + right_sum);
}


std::tuple<std::size_t, std::size_t, int>
find_max_subarray(std::vector<int>& A, std::size_t low, std::size_t high)
{
    if (high == low)
        return std::make_tuple(low, high, A[low]);

    auto mid = (low + high) / 2;

    std::size_t left_low, right_low, cross_low;
    std::size_t left_high, right_high, cross_high;
    int left_sum, right_sum, cross_sum;

    std::tie(left_low, left_high, left_sum) =
            find_max_subarray(A, low, mid);

    std::tie(right_low, right_high, right_sum) =
            find_max_subarray(A, mid + 1, high);

    std::tie(cross_low, cross_high, cross_sum) =
            find_max_crossing_subarray(A, low, mid, high);

    if (left_sum >= right_sum && left_sum >= cross_sum)
        return std::make_tuple(left_low, left_high, left_sum);

    else if (right_sum >= left_sum && right_sum >= cross_sum)
        return std::make_tuple(right_low, right_high, right_sum);

    else
        return std::make_tuple(cross_low, cross_high, cross_sum);
}


#ifndef TEST
int main()
{
    std::vector<int> A = {13, -3, -25, 20,  -3, -16, -23, 18,
                          20, -7,  12, -5, -22,  15,  -4,  7};

    std::size_t low;
    std::size_t high;
    int max_sum;

    std::tie(low, high, max_sum) = find_max_subarray(A, 0, A.size() - 1);
    std::cout << low << ' ' << high << ' ' << max_sum << '\n';
}
#endif

// Author: Susam Pal
// License: MIT


#include <iostream>
#include <vector>


void merge(std::vector<int>& A, std::size_t p, std::size_t q, std::size_t r)
{
    // L = A[p..q], R = A[q+1..r], n1 = q - p + 1, n2 = r - q
    std::vector<int> L(std::begin(A) + p, std::begin(A) + q + 1);
    std::vector<int> R(std::begin(A) + q + 1, std::begin(A) + r + 1);
    auto n1 = L.size();
    auto n2 = R.size();

    std::size_t i = 0;
    std::size_t j = 0;
    std::size_t k = p;

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


void merge_sort(std::vector<int>& A, std::size_t p, std::size_t r)
{
    if (p < r) {
        auto q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}


#ifndef TEST
void print_vector(const std::vector<int>& A)
{
    std::cout << "{";
    for (std::size_t i = 0; i < A.size() - 1; i++) {
        std::cout << A[i] << ", ";
    }
    std::cout << A[A.size() - 1] << "}\n";
}


int main()
{
    std::vector<int> A = {5, 4, 1, 3, 2, 6};
    merge_sort(A, 0, A.size() - 1);
    print_vector(A);
}
#endif

// Author: Susam Pal
// License: MIT


#include <iostream>
#include <vector>


void insertion_sort(std::vector<int>& A)
{
    for (std::size_t j = 1; j < A.size(); j++) {
        // Insert A[j] in sorted sequence A[0..j-1].
        auto key = A[j];
        auto i = j - 1;

        while (i != SIZE_MAX && A[i] > key) { // See note.
            A[i + 1] = A[i];
            i--;
        }

        A[i + 1] = key;
    }
}

// Note: The condition here is a slight departure from the Java and
// Python code which have `i >= 0` in the condition to terminate the
// loop if `i` becomes negative. In this code, `i` is of unsigned type
// which can never be negative.
//
// In C++, when an unsigned 0 is decremented, we get the maximum
// possible integer for that unsigned type. Therefore, when `i` equals
// `SIZE_MAX`, we know that `i = 0` was decremented in the previous
// iteration, and we terminate the loop. This strategy works well here
// because the maximum possible `j` being `SIZE_MAX`, `i` is guaranteed
// to be less than `SIZE_MAX` when we enter the loop.


#ifndef TEST
void print_vector(const std::vector<int>& A)
{
    std::cout << "{";
    for (std::size_t i = 0; i < A.size() - 1; i++)
        std::cout << A[i] << ", ";
    std::cout << A[A.size() - 1] << "}\n";
}


int main()
{
    std::vector<int> A = {5, 4, 1, 3, 2, 6};
    insertion_sort(A);
    print_vector(A);
}
#endif

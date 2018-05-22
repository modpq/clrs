// Author: Susam Pal
// License: MIT


#include <cppunit/extensions/HelperMacros.h>
#include <vector>


void insertion_sort(std::vector<int>& A);


class insertion_sort_test : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(insertion_sort_test);

    CPPUNIT_TEST(test_insertion_sort_typical);
    CPPUNIT_TEST(test_insertion_sort_empty);
    CPPUNIT_TEST(test_insertion_sort_one);
    CPPUNIT_TEST(test_insertion_sort_sorted);
    CPPUNIT_TEST(test_insertion_reverse_sorted);

    CPPUNIT_TEST_SUITE_END();

protected:
    void test_typical();
    void test_insertion_sort_typical();
    void test_insertion_sort_empty();
    void test_insertion_sort_one();
    void test_insertion_sort_sorted();
    void test_insertion_reverse_sorted();
};


CPPUNIT_TEST_SUITE_REGISTRATION(insertion_sort_test);


void insertion_sort_test::test_insertion_sort_typical()
{
    std::vector<int> A = {1, 7, 9, 2, 6, 8};
    insertion_sort(A);
    CPPUNIT_ASSERT((std::vector<int>{1, 2, 6, 7, 8, 9} == A));
}


void insertion_sort_test::test_insertion_sort_empty()
{
    std::vector<int> A;
    insertion_sort(A);
    CPPUNIT_ASSERT((std::vector<int>{} == A));
}


void insertion_sort_test::test_insertion_sort_one()
{
    std::vector<int> A = {5};
    insertion_sort(A);
    CPPUNIT_ASSERT(((std::vector<int>{5}) == A));
}


void insertion_sort_test::test_insertion_sort_sorted()
{
    std::vector<int> A = {1, 2, 6, 7, 8, 9};
    insertion_sort(A);
    CPPUNIT_ASSERT((std::vector<int>{1, 2, 6, 7, 8, 9} == A));
}


void insertion_sort_test::test_insertion_reverse_sorted()
{
    std::vector<int> A = {9, 8, 7, 6, 2, 1};
    insertion_sort(A);
    CPPUNIT_ASSERT((std::vector<int>{1, 2, 6, 7, 8, 9} == A));
}

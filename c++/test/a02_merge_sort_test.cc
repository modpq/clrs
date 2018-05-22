// Author: Susam Pal
// License: MIT


#include <cppunit/extensions/HelperMacros.h>
#include <vector>


void merge(std::vector<int>& A, std::size_t p, std::size_t q, std::size_t r);
void merge_sort(std::vector<int>& A, std::size_t p, std::size_t r);


class merge_sort_test : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(merge_sort_test);

    CPPUNIT_TEST(test_merge_typical);
    CPPUNIT_TEST(test_merge_two_items);
    CPPUNIT_TEST(test_merge_one_item);
    CPPUNIT_TEST(test_merge_sort_example);
    CPPUNIT_TEST(test_merge_sort_typical);
    CPPUNIT_TEST(test_merge_sort_two_items);
    CPPUNIT_TEST(test_merge_sort_one_item);

    CPPUNIT_TEST_SUITE_END();

protected:
    void test_merge_typical();
    void test_merge_two_items();
    void test_merge_one_item();
    void test_merge_sort_example();
    void test_merge_sort_typical();
    void test_merge_sort_two_items();
    void test_merge_sort_one_item();
};


CPPUNIT_TEST_SUITE_REGISTRATION(merge_sort_test);


void merge_sort_test::test_merge_typical()
{
    std::vector<int> A = {1, 7, 9, 2, 6, 8};
    merge(A, 0, 2, A.size() - 1);
    CPPUNIT_ASSERT((std::vector<int>{1, 2, 6, 7, 8, 9} == A));
}


void merge_sort_test::test_merge_two_items()
{
    std::vector<int> A = {1, 7, 9, 2, 6, 8};
    merge(A, 2, 2, 3);
    CPPUNIT_ASSERT((std::vector<int>{1, 7, 2, 9, 6, 8} == A));
}


void merge_sort_test::test_merge_one_item()
{
    std::vector<int> A = {1, 7, 9, 2, 6, 8};
    merge(A, 2, 2, 2);
    CPPUNIT_ASSERT((std::vector<int>{1, 7, 9, 2, 6, 8} == A));
}


void merge_sort_test::test_merge_sort_example()
{
    std::vector<int> A = {5, 4, 1, 3, 2, 6};
    merge_sort(A, 0, A.size() - 1);
    CPPUNIT_ASSERT((std::vector<int>{1, 2, 3, 4, 5, 6} == A));
}


void merge_sort_test::test_merge_sort_typical()
{
    std::vector<int> A = {1, 7, 9, 2, 6, 8};
    merge_sort(A, 0, A.size() - 1);
    CPPUNIT_ASSERT((std::vector<int>{1, 2, 6, 7, 8, 9} == A));
}


void merge_sort_test::test_merge_sort_two_items()
{
    std::vector<int> A = {1, 7, 9, 2, 6, 8};
    merge_sort(A, 2, 3);
    CPPUNIT_ASSERT((std::vector<int>{1, 7, 2, 9, 6, 8} == A));
}


void merge_sort_test::test_merge_sort_one_item()
{
    std::vector<int> A = {1, 7, 9, 2, 6, 8};
    merge_sort(A, 2, 2);
    CPPUNIT_ASSERT((std::vector<int>{1, 7, 9, 2, 6, 8} == A));
}

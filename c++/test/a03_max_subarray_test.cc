// Author: Susam Pal
// License: MIT


#include <cppunit/extensions/HelperMacros.h>
#include <vector>
#include <tuple>
#include <stdexcept>


std::tuple<std::size_t, std::size_t, int>
find_max_crossing_subarray(std::vector<int>& A,std::size_t low,
                           std::size_t mid, std::size_t high);

std::tuple<std::size_t, std::size_t, int>
find_max_subarray(std::vector<int>& A, std::size_t low, std::size_t high);


class max_subarray_test : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(max_subarray_test);

    CPPUNIT_TEST(test_find_max_crossing_subarray_all_positives);
    CPPUNIT_TEST(test_find_max_crossing_subarray_negatives);
    CPPUNIT_TEST(test_find_max_crossing_subarray_three_items);
    CPPUNIT_TEST(test_find_max_crossing_subarray_two_items);
    CPPUNIT_TEST(test_find_max_crossing_subarray_one_item);
    CPPUNIT_TEST(test_find_max_crossing_subarray_one_item_vector);
    CPPUNIT_TEST(test_find_max_subarray_all_positives);
    CPPUNIT_TEST(test_find_max_subarray_negatives);
    CPPUNIT_TEST(test_find_max_subarray_three_items);
    CPPUNIT_TEST(test_find_max_subarray_two_items);
    CPPUNIT_TEST(test_find_max_subarray_one_item);
    CPPUNIT_TEST_SUITE_END();

protected:
    void test_find_max_crossing_subarray_all_positives();
    void test_find_max_crossing_subarray_negatives();
    void test_find_max_crossing_subarray_three_items();
    void test_find_max_crossing_subarray_two_items();
    void test_find_max_crossing_subarray_one_item();
    void test_find_max_crossing_subarray_one_item_vector();
    void test_find_max_subarray_all_positives();
    void test_find_max_subarray_negatives();
    void test_find_max_subarray_three_items();
    void test_find_max_subarray_two_items();
    void test_find_max_subarray_one_item();
};


CPPUNIT_TEST_SUITE_REGISTRATION(max_subarray_test);


void max_subarray_test::test_find_max_crossing_subarray_all_positives()
{
    std::vector<int> A = {1, 7, 9, 2, 6, 8};
    auto result = find_max_crossing_subarray(A, 0, 2, A.size() - 1);
    CPPUNIT_ASSERT(std::make_tuple(0, 5, 33) == result);
}


void max_subarray_test::test_find_max_crossing_subarray_negatives()
{
    std::vector<int> A = {1, -7, 9, 2, -6, 8};
    auto result = find_max_crossing_subarray(A, 0, 2, A.size() - 1);
    CPPUNIT_ASSERT(std::make_tuple(2, 5, 13) == result);
}


void max_subarray_test::test_find_max_crossing_subarray_three_items()
{
    std::vector<int> A = {1, -7, 9, 2, -6, 8};
    auto result = find_max_crossing_subarray(A, 2, 3, 4);
    CPPUNIT_ASSERT(std::make_tuple(2, 4, 5) == result);
}


void max_subarray_test::test_find_max_crossing_subarray_two_items()
{
    std::vector<int> A = {1, -7, 9, 2, -6, 8};
    auto result = find_max_crossing_subarray(A, 2, 2, 3);
    CPPUNIT_ASSERT(std::make_tuple(2, 3, 11) == result);
}


void max_subarray_test::test_find_max_crossing_subarray_one_item()
{
    std::vector<int> A = {1, -7, 9, 2, -6, 8};
    CPPUNIT_ASSERT_THROW(find_max_crossing_subarray(A, 2, 2, 2),
                         std::invalid_argument);
}


void max_subarray_test::test_find_max_crossing_subarray_one_item_vector()
{
    std::vector<int> A = {1};
    CPPUNIT_ASSERT_THROW(find_max_crossing_subarray(A, 0, 0, 0),
                         std::invalid_argument);
}


void max_subarray_test::test_find_max_subarray_all_positives()
{
    std::vector<int> A = {1, 7, 9, 2, 6, 8};
    auto result = find_max_subarray(A, 0, A.size() - 1);
    CPPUNIT_ASSERT(std::make_tuple(0, 5, 33) == result);
}


void max_subarray_test::test_find_max_subarray_negatives()
{
    std::vector<int> A = {1, -7, 9, 2, -6, 8};
    auto result = find_max_subarray(A, 0, A.size() - 1);
    CPPUNIT_ASSERT(std::make_tuple(2, 5, 13) == result);
}


void max_subarray_test::test_find_max_subarray_three_items()
{
    std::vector<int> A = {1, -7, 9, 2, -6, 8};
    auto result = find_max_subarray(A, 0, A.size() - 1);
    CPPUNIT_ASSERT(std::make_tuple(2, 5, 13) == result);
}


void max_subarray_test::test_find_max_subarray_two_items()
{
    std::vector<int> A = {1, -7, 9, 2, -6, 8};
    auto result = find_max_subarray(A, 3, 4);
    CPPUNIT_ASSERT(std::make_tuple(3, 3, 2) == result);
}


void max_subarray_test::test_find_max_subarray_one_item()
{
    std::vector<int> A = {1, -7, 9, 2, -6, 8};
    auto result = find_max_subarray(A, 2, 2);
    CPPUNIT_ASSERT(std::make_tuple(2, 2, 9) == result);
}

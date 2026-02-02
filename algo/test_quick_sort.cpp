#include <gtest/gtest.h>
#include "quick_sort.cpp"

TEST(QuickSortTest, EmptyArray) {
    std::vector<int> arr;
    std::vector<int> expected;
    EXPECT_EQ(quickSort(arr), expected);
}

TEST(QuickSortTest, SingleElementArray) {
    std::vector<int> arr = {5};
    std::vector<int> expected = {5};
    EXPECT_EQ(quickSort(arr), expected);
}

TEST(QuickSortTest, AlreadySortedArray) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(quickSort(arr), expected);
}

TEST(QuickSortTest, ReverseSortedArray) {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(quickSort(arr), expected);
}

TEST(QuickSortTest, UnsortedArray) {
    std::vector<int> arr = {3, 6, 1, 8, 2, 4};
    std::vector<int> expected = {1, 2, 3, 4, 6, 8};
    EXPECT_EQ(quickSort(arr), expected);
}

TEST(QuickSortTest, ArrayWithDuplicates) {
    std::vector<int> arr = {3, 3, 1, 1, 2, 2};
    std::vector<int> expected = {1, 1, 2, 2, 3, 3};
    EXPECT_EQ(quickSort(arr), expected);
}

TEST(QuickSortTest, ArrayWithNegativeNumbers) {
    std::vector<int> arr = {3, -1, 1, -2, 2};
    std::vector<int> expected = {-2, -1, 1, 2, 3};
    EXPECT_EQ(quickSort(arr), expected);
}

TEST(QuickSortTest, ArrayWithZero) {
    std::vector<int> arr = {3, 0, 1, 0, 2};
    std::vector<int> expected = {0, 0, 1, 2, 3};
    EXPECT_EQ(quickSort(arr), expected);
}

TEST(QuickSortTest, LargeArray) {
    std::vector<int> arr = {3, 6, 1, 8, 2, 4, 5, 7, 9, 0};
    std::vector<int> expected = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ(quickSort(arr), expected);
}

TEST(QuickSortTest, EdgeCase) {
    std::vector<int> arr = {1, 1, 1, 1, 1};
    std::vector<int> expected = {1, 1, 1, 1, 1};
    EXPECT_EQ(quickSort(arr), expected);
}
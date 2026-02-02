#include <gtest/gtest.h>
#include "quick_sort.h"

TEST(QuickSortTest, Empty) {
    std::vector<int> input = {};
    std::vector<int> expected = {};
    std::vector<int> actual = quickSort(input);
    EXPECT_EQ(actual, expected);
}

TEST(QuickSortTest, Single) {
    std::vector<int> input = {1};
    std::vector<int> expected = {1};
    std::vector<int> actual = quickSort(input);
    EXPECT_EQ(actual, expected);
}

TEST(QuickSortTest, AlreadySorted) {
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    std::vector<int> actual = quickSort(input);
    EXPECT_EQ(actual, expected);
}

TEST(QuickSortTest, ReverseSorted) {
    std::vector<int> input = {5, 4, 3, 2, 1};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    std::vector<int> actual = quickSort(input);
    EXPECT_EQ(actual, expected);
}

TEST(QuickSortTest, Unsorted) {
    std::vector<int> input = {3, 6, 8, 10, 1, 2, 1};
    std::vector<int> expected = {1, 1, 2, 3, 6, 8, 10};
    std::vector<int> actual = quickSort(input);
    EXPECT_EQ(actual, expected);
}

TEST(QuickSortTest, Duplicates) {
    std::vector<int> input = {4, 2, 9, 6, 5, 1, 8, 3, 7, 4, 5, 6};
    std::vector<int> expected = {1, 2, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9};
    std::vector<int> actual = quickSort(input);
    EXPECT_EQ(actual, expected);
}

TEST(QuickSortTest, Negative) {
    std::vector<int> input = {3, -6, 8, -10, 1, 2, -1};
    std::vector<int> expected = {-10, -6, -1, 1, 2, 3, 8};
    std::vector<int> actual = quickSort(input);
    EXPECT_EQ(actual, expected);
}

TEST(QuickSortTest, Large) {
    std::vector<int> input = {3, 6, 8, 10, 1, 2, 1};
    std::vector<int> expected = {1, 1, 2, 3, 6, 8, 10};
    std::vector<int> actual = quickSort(input);
    EXPECT_EQ(actual, expected);
}

TEST(QuickSortTest, EdgeCase) {
    std::vector<int> input = {0};
    std::vector<int> expected = {0};
    std::vector<int> actual = quickSort(input);
    EXPECT_EQ(actual, expected);
}

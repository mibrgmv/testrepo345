#include <gtest/gtest.h>
#include "quick_sort.h"
#include <vector>
#include <algorithm>

TEST(QuickSortTest, Empty) {
    std::vector<int> arr;
    std::vector<int> result = quickSort(arr);
    EXPECT_EQ(result, std::vector<int>());
}

TEST(QuickSortTest, Single) {
    std::vector<int> arr = {5};
    std::vector<int> result = quickSort(arr);
    EXPECT_EQ(result, std::vector<int>{5});
}

TEST(QuickSortTest, AlreadySorted) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> result = quickSort(arr);
    EXPECT_EQ(result, std::vector<int>{1, 2, 3, 4, 5});
}

TEST(QuickSortTest, ReverseSorted) {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    std::vector<int> result = quickSort(arr);
    EXPECT_EQ(result, std::vector<int>{1, 2, 3, 4, 5});
}

TEST(QuickSortTest, Unsorted) {
    std::vector<int> arr = {3, 6, 8, 10, 1, 2, 1};
    std::vector<int> result = quickSort(arr);
    EXPECT_EQ(result, std::vector<int>{1, 1, 2, 3, 6, 8, 10});
}

TEST(QuickSortTest, Duplicates) {
    std::vector<int> arr = {4, 2, 9, 6, 5, 1, 8, 3, 7, 4, 5, 6};
    std::vector<int> result = quickSort(arr);
    EXPECT_EQ(result, std::vector<int>{1, 2, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9});
}

TEST(QuickSortTest, Negative) {
    std::vector<int> arr = {-3, -6, -8, -10, -1, -2, -1};
    std::vector<int> result = quickSort(arr);
    EXPECT_EQ(result, std::vector<int>{-10, -8, -6, -3, -2, -1, -1});
}

TEST(QuickSortTest, Mixed) {
    std::vector<int> arr = {-3, 6, -8, 10, -1, 2, -1};
    std::vector<int> result = quickSort(arr);
    EXPECT_EQ(result, std::vector<int>{-8, -3, -1, -1, 2, 6, 10});
}

TEST(QuickSortTest, Large) {
    std::vector<int> arr = {4, 65, 2, -31};
    std::vector<int> result = quickSort(arr);
    EXPECT_EQ(result, std::vector<int>{-31, 2, 4, 65});
}

TEST(QuickSortTest, AlreadySortedWithDuplicates) {
    std::vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4};
    std::vector<int> result = quickSort(arr);
    EXPECT_EQ(result, std::vector<int>{1, 1, 2, 2, 3, 3, 4, 4});
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
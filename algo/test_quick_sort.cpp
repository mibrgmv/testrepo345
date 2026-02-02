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
    std::vector<int> arr = {3, 6, 8, 10, 1, 4, 7};
    std::vector<int> expected = {1, 3, 4, 6, 7, 8, 10};
    EXPECT_EQ(quickSort(arr), expected);
}

TEST(QuickSortTest, ArrayWithDuplicates) {
    std::vector<int> arr = {3, 6, 8, 10, 1, 4, 7, 3, 6};
    std::vector<int> expected = {1, 3, 3, 4, 6, 6, 7, 8, 10};
    EXPECT_EQ(quickSort(arr), expected);
}

TEST(QuickSortTest, ArrayWithNegativeNumbers) {
    std::vector<int> arr = {3, -6, 8, -10, 1, 4, -7};
    std::vector<int> expected = {-10, -7, -6, 1, 3, 4, 8};
    EXPECT_EQ(quickSort(arr), expected);
}

TEST(QuickSortTest, ArrayWithZero) {
    std::vector<int> arr = {3, 0, 8, 10, 1, 4, 7};
    std::vector<int> expected = {0, 1, 3, 4, 7, 8, 10};
    EXPECT_EQ(quickSort(arr), expected);
}

TEST(QuickSortTest, LargeArray) {
    std::vector<int> arr = {3, 6, 8, 10, 1, 4, 7, 3, 6, 8, 10, 1, 4, 7};
    std::vector<int> expected = {1, 1, 3, 3, 4, 4, 6, 6, 7, 7, 8, 8, 10, 10};
    EXPECT_EQ(quickSort(arr), expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

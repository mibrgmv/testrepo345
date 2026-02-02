#include <iostream>
#include <vector>
#include <gtest/gtest.h>

std::vector<int> quickSort(std::vector<int>& arr) {
    if (arr.size() <= 1) {
        return arr;
    }
    int pivot = arr[arr.size() / 2];
    std::vector<int> left, middle, right;
    for (int x : arr) {
        if (x < pivot) {
            left.push_back(x);
        } else if (x == pivot) {
            middle.push_back(x);
        } else {
            right.push_back(x);
        }
    }
    left = quickSort(left);
    right = quickSort(right);
    left.insert(left.end(), middle.begin(), middle.end());
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

TEST(QuickSortTest, QuickSort) {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> testCases = {
        {{3, 6, 8, 10, 1, 2, 1}, {1, 1, 2, 3, 6, 8, 10}},
        {{5, 2, 9, 1, 7, 3}, {1, 2, 3, 5, 7, 9}},
        {{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}},
        {{}, {}},
        {{1}, {1}},
        {{1, 2}, {1, 2}},
        {{2, 1}, {1, 2}},
        {{5, 4, 3, 2, 1}, {1, 2, 3, 4, 5}},
        {{1, 1, 1, 2, 2, 2}, {1, 1, 1, 2, 2, 2}},
        {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}}
    };
    for (auto& tc : testCases) {
        std::vector<int> result = quickSort(tc.first);
        EXPECT_EQ(result, tc.second);
    }
}

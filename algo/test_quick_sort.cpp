#include <gtest/gtest.h>
#include "quick_sort.h"

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

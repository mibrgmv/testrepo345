#include <iostream>
#include <vector>

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

void printArray(const std::vector<int>& arr) {
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> testCases[] = {
        {3, 6, 8, 10, 1, 2, 1},
        {5, 2, 9, 1, 7},
        {1, 1, 1, 1, 1},
        {},
        {1},
        {5, 4, 3, 2, 1},
        {1, 2, 3, 4, 5},
        {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {5, 2, 8, 12, 3}
    };
    std::vector<int> expectedResults[] = {
        {1, 1, 2, 3, 6, 8, 10},
        {1, 2, 5, 7, 9},
        {1, 1, 1, 1, 1},
        {},
        {1},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {2, 3, 5, 8, 12}
    };
    for (int i = 0; i < 10; i++) {
        std::vector<int> result = quickSort(testCases[i]);
        if (result != expectedResults[i]) {
            std::cout << "quickSort failed for test case " << i << std::endl;
        } else {
            std::cout << "quickSort passed for test case " << i << std::endl;
        }
    }
    return 0;
}
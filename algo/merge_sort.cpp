#include <iostream>
#include <vector>

std::vector<int> mergeSort(std::vector<int>& arr) {
    if (arr.size() <= 1) {
        return arr;
    }
    int mid = arr.size() / 2;
    std::vector<int> leftHalf(arr.begin(), arr.begin() + mid);
    std::vector<int> rightHalf(arr.begin() + mid, arr.end());
    leftHalf = mergeSort(leftHalf);
    rightHalf = mergeSort(rightHalf);
    return merge(leftHalf, rightHalf);
}

std::vector<int> merge(std::vector<int>& left, std::vector<int>& right) {
    std::vector<int> merged;
    int leftIndex = 0;
    int rightIndex = 0;
    while (leftIndex < left.size() && rightIndex < right.size()) {
        if (left[leftIndex] <= right[rightIndex]) {
            merged.push_back(left[leftIndex]);
            leftIndex++;
        } else {
            merged.push_back(right[rightIndex]);
            rightIndex++;
        }
    }
    while (leftIndex < left.size()) {
        merged.push_back(left[leftIndex]);
        leftIndex++;
    }
    while (rightIndex < right.size()) {
        merged.push_back(right[rightIndex]);
        rightIndex++;
    }
    return merged;
}
package algo

import (
    "testing"
)

func quickSort(arr []int) []int {
    if len(arr) <= 1 {
        return arr
    }
    pivot := arr[len(arr)/2]
    var left, middle, right []int
    for _, x := range arr {
        if x < pivot {
            left = append(left, x)
        } else if x == pivot {
            middle = append(middle, x)
        } else {
            right = append(right, x)
        }
    }
    left = quickSort(left)
    right = quickSort(right)
    return append(append(left, middle...), right...)
}

func TestQuickSort(t *testing.T) {
    testCases := [][]int{
        {3, 6, 8, 10, 1, 2, 1},
        {5, 2, 9, 1, 7},
        {1, 1, 1, 1, 1},
        {},
        {1},
        {5, 4, 3, 2, 1},
        {1, 2, 3, 4, 5},
        {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {5, 2, 8, 12, 3},
    }
    expectedResults := [][]int{
        {1, 1, 2, 3, 6, 8, 10},
        {1, 2, 5, 7, 9},
        {1, 1, 1, 1, 1},
        {},
        {1},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {2, 3, 5, 8, 12},
    }
    for i, testCase := range testCases {
        result := quickSort(testCase)
        if len(result) != len(expectedResults[i]) {
            t.Errorf("quickSort(%v) = %v, want %v", testCase, result, expectedResults[i])
        }
        for j, val := range result {
            if val != expectedResults[i][j] {
                t.Errorf("quickSort(%v) = %v, want %v", testCase, result, expectedResults[i])
            }
        }
    }
}
package main

import (
    "fmt"
    "testing"
)

func heapify(arr []int, n, i int) {
    largest := i
    left := 2*i + 1
    right := 2*i + 2
    if left < n && arr[i] < arr[left] {
        largest = left
    }
    if right < n && arr[largest] < arr[right] {
        largest = right
    }
    if largest != i {
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)
    }
}

func heapSort(arr []int) []int {
    n := len(arr)
    for i := n/2 - 1; i >= 0; i-- {
        heapify(arr, n, i)
    }
    for i := n - 1; i > 0; i-- {
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)
    }
    return arr
}

func TestHeapSort(t *testing.T) {
    testCases := [][]int{
        {5, 2, 8, 3, 1},
        {10, 9, 8, 7, 6},
        {1, 2, 3, 4, 5},
        {5, 1, 3, 2, 4},
        {1, 1, 1, 1, 1},
        {5, 5, 5, 5, 5},
        {1, 2, 3, 4, 5, 6},
        {6, 5, 4, 3, 2, 1},
        {1, 1, 2, 2, 3},
        {3, 2, 1}
    }
    expectedResults := [][]int{
        {1, 2, 3, 5, 8},
        {6, 7, 8, 9, 10},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 1, 1, 1, 1},
        {5, 5, 5, 5, 5},
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6},
        {1, 1, 2, 2, 3},
        {1, 2, 3}
    }
    for i, testCase := range testCases {
        result := heapSort(testCase)
        if len(result) != len(expectedResults[i]) {
            t.Errorf("Test case %d failed: expected length %d, got %d", i+1, len(expectedResults[i]), len(result))
        }
        for j := range result {
            if result[j] != expectedResults[i][j] {
                t.Errorf("Test case %d failed: expected %v, got %v", i+1, expectedResults[i], result)
            }
        }
    }
}

func main() {
    fmt.Println("Heap sort test")
}
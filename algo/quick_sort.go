// Go implementation of quick sort
package main

import (
    "fmt"
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
    testCases := []struct {
        arr     []int
        expected []int
    }{
        {[]int{3, 6, 8, 10, 1, 2, 1}, []int{1, 1, 2, 3, 6, 8, 10}},
        {[]int{5, 2, 9, 1, 7}, []int{1, 2, 5, 7, 9}},
        {[]int{1, 1, 1, 1}, []int{1, 1, 1, 1}},
        {[]int{}, []int{}},
        {[]int{1}, []int{1}},
        {[]int{1, 2}, []int{1, 2}},
        {[]int{2, 1}, []int{1, 2}},
        {[]int{5, 4, 3, 2, 1}, []int{1, 2, 3, 4, 5}},
        {[]int{1, 2, 3, 4, 5}, []int{1, 2, 3, 4, 5}},
        {[]int{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}}
    }
    for _, tc := range testCases {
        if got := quickSort(tc.arr); !equal(got, tc.expected) {
            t.Errorf("quickSort(%v) = %v, want %v", tc.arr, got, tc.expected)
        }
    }
}

func equal(a, b []int) bool {
    if len(a) != len(b) {
        return false
    }
    for i := range a {
        if a[i] != b[i] {
            return false
        }
    }
    return true
}

package algo

import (
    "reflect"
    "testing"
)

func TestQuickSort(t *testing.T) {
    testCases := []struct {
        arr     []int
        expected []int
    }{
        {[]int{3, 6, 8, 10, 1, 2, 1}, []int{1, 1, 2, 3, 6, 8, 10}},
        {[]int{5, 2, 9, 1, 7, 3}, []int{1, 2, 3, 5, 7, 9}},
        {[]int{1, 1, 1, 1, 1}, []int{1, 1, 1, 1, 1}},
        {[]int{}, []int{}},
        {[]int{1}, []int{1}},
        {[]int{1, 2}, []int{1, 2}},
        {[]int{2, 1}, []int{1, 2}},
        {[]int{5, 4, 3, 2, 1}, []int{1, 2, 3, 4, 5}},
        {[]int{1, 1, 1, 2, 2, 2}, []int{1, 1, 1, 2, 2, 2}},
        {[]int{1, 2, 3, 4, 5}, []int{1, 2, 3, 4, 5}}
    }
    for _, tc := range testCases {
        if !reflect.DeepEqual(quickSort(tc.arr), tc.expected) {
            t.Errorf("quickSort(%v) = %v, want %v", tc.arr, quickSort(tc.arr), tc.expected)
        }
    }
}
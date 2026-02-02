package algo

import (
    "testing"
)

func TestQuickSort(t *testing.T) {
    tests := []struct {
        name string
        arr  []int
        want []int
    }{
        {"empty array", []int{}, []int{}},
        {"single element array", []int{5}, []int{5}},
        {"already sorted array", []int{1, 2, 3, 4, 5}, []int{1, 2, 3, 4, 5}},
        {"reverse sorted array", []int{5, 4, 3, 2, 1}, []int{1, 2, 3, 4, 5}},
        {"unsorted array", []int{3, 6, 1, 8, 2, 4}, []int{1, 2, 3, 4, 6, 8}},
        {"array with duplicates", []int{3, 3, 1, 1, 2, 2}, []int{1, 1, 2, 2, 3, 3}},
        {"array with negative numbers", []int{3, -1, 1, -2, 2}, []int{-2, -1, 1, 2, 3}},
        {"array with zero", []int{3, 0, 1, 0, 2}, []int{0, 0, 1, 2, 3}},
        {"large array", []int{3, 6, 1, 8, 2, 4, 5, 7, 9, 0}, []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}},
        {"edge case", []int{1, 1, 1, 1, 1}, []int{1, 1, 1, 1, 1}},
    }
    for _, tt := range tests {
        t.Run(tt.name, func(t *testing.T) {
            if got := QuickSort(tt.arr); !reflect.DeepEqual(got, tt.want) {
                t.Errorf("QuickSort() = %v, want %v", got, tt.want)
            }
        })
    }
}
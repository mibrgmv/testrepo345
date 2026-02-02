package algo

import (
    "fmt"
    "testing"
)

func TestQuickSort(t *testing.T) {
    tests := []struct {
        name  string
        input []int
        want  []int
    }{
        {"empty array", []int{}, []int{}},
        {"single element array", []int{5}, []int{5}},
        {"already sorted array", []int{1, 2, 3, 4, 5}, []int{1, 2, 3, 4, 5}},
        {"reverse sorted array", []int{5, 4, 3, 2, 1}, []int{1, 2, 3, 4, 5}},
        {"unsorted array", []int{3, 6, 8, 10, 1, 4, 7}, []int{1, 3, 4, 6, 7, 8, 10}},
        {"array with duplicates", []int{3, 6, 8, 10, 1, 4, 7, 3, 6}, []int{1, 3, 3, 4, 6, 6, 7, 8, 10}},
        {"array with negative numbers", []int{3, -6, 8, -10, 1, 4, -7}, []int{-10, -7, -6, 1, 3, 4, 8}},
        {"array with zero", []int{3, 0, 8, 10, 1, 4, 7}, []int{0, 1, 3, 4, 7, 8, 10}},
        {"large array", []int{3, 6, 8, 10, 1, 4, 7, 3, 6, 8, 10, 1, 4, 7}, []int{1, 1, 3, 3, 4, 4, 6, 6, 7, 7, 8, 8, 10, 10}},
        {"already sorted large array", []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}},
    }
    for _, tt := range tests {
        t.Run(tt.name, func(t *testing.T) {
            if got := quickSort(tt.input); !equal(got, tt.want) {
                t.Errorf("quickSort() = %v, want %v", got, tt.want)
            }
        })
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

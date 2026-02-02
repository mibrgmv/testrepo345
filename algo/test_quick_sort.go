package algo

import (
    "reflect"
    "testing"
)

func TestQuickSort(t *testing.T) {
    tests := []struct {
        name  string
        input []int
        want  []int
    }{
        {
            "empty",
            []int{},
            []int{},
        },
        {
            "single",
            []int{1},
            []int{1},
        },
        {
            "already sorted",
            []int{1, 2, 3, 4, 5},
            []int{1, 2, 3, 4, 5},
        },
        {
            "reverse sorted",
            []int{5, 4, 3, 2, 1},
            []int{1, 2, 3, 4, 5},
        },
        {
            "unsorted",
            []int{3, 6, 8, 10, 1, 2, 1},
            []int{1, 1, 2, 3, 6, 8, 10},
        },
        {
            "duplicates",
            []int{4, 2, 9, 6, 5, 1, 8, 3, 7, 4, 5, 6},
            []int{1, 2, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9},
        },
        {
            "negative",
            []int{3, -6, 8, -10, 1, 2, -1},
            []int{-10, -6, -1, 1, 2, 3, 8},
        },
        {
            "large",
            []int{3, 6, 8, 10, 1, 2, 1},
            []int{1, 1, 2, 3, 6, 8, 10},
        },
        {
            "edge case",
            []int{0},
            []int{0},
        },
    }
    for _, tt := range tests {
        t.Run(tt.name, func(t *testing.T) {
            got := quickSort(tt.input)
            if !reflect.DeepEqual(got, tt.want) {
                t.Errorf("quickSort() = %v, want %v", got, tt.want)
            }
        })
    }
}
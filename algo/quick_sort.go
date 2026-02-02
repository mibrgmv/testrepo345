package algo

import (
    "fmt"
)

func QuickSort(arr []int) []int {
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
    left = QuickSort(left)
    right = QuickSort(right)
    var result []int
    result = append(result, left...)
    result = append(result, middle...)
    result = append(result, right...)
    return result
}
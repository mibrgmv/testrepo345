package algo

import (
    "fmt"
)

func mergeSort(arr []int) []int {
    if len(arr) <= 1 {
        return arr
    }
    mid := len(arr) / 2
    leftHalf := mergeSort(arr[:mid])
    rightHalf := mergeSort(arr[mid:])
    return merge(leftHalf, rightHalf)
}

func merge(left, right []int) []int {
    merged := make([]int, 0)
    leftIndex := 0
    rightIndex := 0
    for leftIndex < len(left) && rightIndex < len(right) {
        if left[leftIndex] <= right[rightIndex] {
            merged = append(merged, left[leftIndex])
            leftIndex++
        } else {
            merged = append(merged, right[rightIndex])
            rightIndex++
        }
    }
    merged = append(merged, left[leftIndex:]...)
    merged = append(merged, right[rightIndex:]...)
    return merged
}
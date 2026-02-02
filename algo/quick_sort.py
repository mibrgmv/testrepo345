def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

import unittest

class TestQuickSort(unittest.TestCase):
    def test_quick_sort(self):
        test_cases = [
            ([3, 6, 8, 10, 1, 2, 1], [1, 1, 2, 3, 6, 8, 10]),
            ([5, 2, 9, 1, 7, 3], [1, 2, 3, 5, 7, 9]),
            ([1, 1, 1, 1, 1], [1, 1, 1, 1, 1]),
            ([], []),
            ([1], [1]),
            ([1, 2], [1, 2]),
            ([2, 1], [1, 2]),
            ([5, 4, 3, 2, 1], [1, 2, 3, 4, 5]),
            ([1, 1, 1, 2, 2, 2], [1, 1, 1, 2, 2, 2]),
            ([1, 2, 3, 4, 5], [1, 2, 3, 4, 5])
        ]
        for arr, expected in test_cases:
            self.assertEqual(quick_sort(arr), expected)

if __name__ == '__main__':
    unittest.main()
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
            ([5, 2, 9, 1, 7], [1, 2, 5, 7, 9]),
            ([1, 1, 1, 1, 1], [1, 1, 1, 1, 1]),
            ([], []),
            ([1], [1]),
            ([5, 4, 3, 2, 1], [1, 2, 3, 4, 5]),
            ([1, 2, 3, 4, 5], [1, 2, 3, 4, 5]),
            ([10, 9, 8, 7, 6, 5, 4, 3, 2, 1], [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]),
            ([1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]),
            ([5, 2, 8, 12, 3], [2, 3, 5, 8, 12])
        ]
        for test_case in test_cases:
            self.assertEqual(quick_sort(test_case[0]), test_case[1])

if __name__ == '__main__':
    unittest.main()
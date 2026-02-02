import unittest
from quick_sort import quick_sort

class TestQuickSort(unittest.TestCase):
    def test_empty_array(self):
        self.assertEqual(quick_sort([]), [])
    def test_single_element_array(self):
        self.assertEqual(quick_sort([5]), [5])
    def test_already_sorted_array(self):
        self.assertEqual(quick_sort([1, 2, 3, 4, 5]), [1, 2, 3, 4, 5])
    def test_reverse_sorted_array(self):
        self.assertEqual(quick_sort([5, 4, 3, 2, 1]), [1, 2, 3, 4, 5])
    def test_unsorted_array(self):
        self.assertEqual(quick_sort([3, 6, 8, 10, 1, 4, 7]), [1, 3, 4, 6, 7, 8, 10])
    def test_array_with_duplicates(self):
        self.assertEqual(quick_sort([3, 6, 8, 10, 1, 4, 7, 3, 6]), [1, 3, 3, 4, 6, 6, 7, 8, 10])
    def test_array_with_negative_numbers(self):
        self.assertEqual(quick_sort([3, -6, 8, -10, 1, 4, -7]), [-10, -7, -6, 1, 3, 4, 8])
    def test_array_with_zero(self):
        self.assertEqual(quick_sort([3, 0, 8, 10, 1, 4, 7]), [0, 1, 3, 4, 7, 8, 10])
    def test_large_array(self):
        import random
        arr = [random.randint(0, 100) for _ in range(100)]
        self.assertEqual(quick_sort(arr), sorted(arr))

if __name__ == '__main__':
    unittest.main()
import unittest
from merge_sort import merge_sort

class TestMergeSort(unittest.TestCase):
    def test_empty_array(self):
        self.assertEqual(merge_sort([]), [])

    def test_single_element_array(self):
        self.assertEqual(merge_sort([5]), [5])

    def test_already_sorted_array(self):
        self.assertEqual(merge_sort([1, 2, 3, 4, 5]), [1, 2, 3, 4, 5])

    def test_reverse_sorted_array(self):
        self.assertEqual(merge_sort([5, 4, 3, 2, 1]), [1, 2, 3, 4, 5])

    def test_unsorted_array(self):
        self.assertEqual(merge_sort([3, 6, 1, 8, 2, 4]), [1, 2, 3, 4, 6, 8])

    def test_array_with_duplicates(self):
        self.assertEqual(merge_sort([4, 2, 9, 6, 5, 1, 8, 3, 7, 4, 5, 6]), [1, 2, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9])

    def test_large_array(self):
        import random
        arr = [random.randint(0, 1000) for _ in range(1000)]
        self.assertEqual(merge_sort(arr), sorted(arr))

    def test_negative_numbers(self):
        self.assertEqual(merge_sort([-5, -2, 0, 2, 5]), [-5, -2, 0, 2, 5])

    def test_float_numbers(self):
        self.assertEqual(merge_sort([5.5, 2.2, 8.8, 1.1, 9.9]), [1.1, 2.2, 5.5, 8.8, 9.9])

if __name__ == '__main__':
    unittest.main()
import unittest
from quick_sort import quick_sort

class TestQuickSort(unittest.TestCase):
    def test_empty(self):
        self.assertEqual(quick_sort([]), [])
    def test_single(self):
        self.assertEqual(quick_sort([1]), [1])
    def test_already_sorted(self):
        self.assertEqual(quick_sort([1, 2, 3, 4, 5]), [1, 2, 3, 4, 5])
    def test_reverse_sorted(self):
        self.assertEqual(quick_sort([5, 4, 3, 2, 1]), [1, 2, 3, 4, 5])
    def test_unsorted(self):
        self.assertEqual(quick_sort([3, 6, 8, 10, 1, 2, 1]), [1, 1, 2, 3, 6, 8, 10])
    def test_duplicates(self):
        self.assertEqual(quick_sort([4, 2, 9, 6, 5, 1, 8, 3, 7, 4, 5, 6]), [1, 2, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9])
    def test_negative(self):
        self.assertEqual(quick_sort([3, -6, 8, -10, 1, 2, -1]), [-10, -6, -1, 1, 2, 3, 8])
    def test_large(self):
        import random
        arr = [random.randint(0, 1000) for _ in range(100)]
        self.assertEqual(quick_sort(arr), sorted(arr))
    def test_edge_case(self):
        self.assertEqual(quick_sort([0]), [0])
if __name__ == '__main__':
    unittest.main()
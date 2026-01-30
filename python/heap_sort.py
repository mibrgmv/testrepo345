import unittest

def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2
    if left < n and arr[i] < arr[left]:
        largest = left
    if right < n and arr[largest] < arr[right]:
        largest = right
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)
    return arr

class TestHeapSort(unittest.TestCase):
    def test_heap_sort(self):
        test_cases = [
            ([5, 2, 8, 3, 1], [1, 2, 3, 5, 8]),
            ([10, 9, 8, 7, 6], [6, 7, 8, 9, 10]),
            ([1, 2, 3, 4, 5], [1, 2, 3, 4, 5]),
            ([5, 1, 3, 2, 4], [1, 2, 3, 4, 5]),
            ([1, 1, 1, 1, 1], [1, 1, 1, 1, 1]),
            ([5, 5, 5, 5, 5], [5, 5, 5, 5, 5]),
            ([1, 2, 3, 4, 5, 6], [1, 2, 3, 4, 5, 6]),
            ([6, 5, 4, 3, 2, 1], [1, 2, 3, 4, 5, 6]),
            ([1, 1, 2, 2, 3], [1, 1, 2, 2, 3]),
            ([3, 2, 1], [1, 2, 3])
        ]
        for arr, expected in test_cases:
            self.assertEqual(heap_sort(arr[:]), expected)

test = unittest.TestLoader().loadTestsFromTestCase(TestHeapSort)
unittest.TextTestRunner(verbosity=2).run(test)
using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

public class HeapSort
{
    public static int[] Sort(int[] arr)
    {
        int n = arr.Length;
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            Heapify(arr, n, i);
        }
        for (int i = n - 1; i > 0; i--)
        {
            int temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;
            Heapify(arr, i, 0);
        }
        return arr;
    }

    private static void Heapify(int[] arr, int n, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[i] < arr[left])
        {
            largest = left;
        }
        if (right < n && arr[largest] < arr[right])
        {
            largest = right;
        }
        if (largest != i)
        {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            Heapify(arr, n, largest);
        }
    }
}

[TestClass]
public class HeapSortTest
{
    [TestMethod]
    public void TestHeapSort()
    {
        int[][] testCases = new int[][]
        {
            new int[] {5, 2, 8, 3, 1},
            new int[] {10, 9, 8, 7, 6},
            new int[] {1, 2, 3, 4, 5},
            new int[] {5, 1, 3, 2, 4},
            new int[] {1, 1, 1, 1, 1},
            new int[] {5, 5, 5, 5, 5},
            new int[] {1, 2, 3, 4, 5, 6},
            new int[] {6, 5, 4, 3, 2, 1},
            new int[] {1, 1, 2, 2, 3},
            new int[] {3, 2, 1}
        };
        int[][] expectedResults = new int[][]
        {
            new int[] {1, 2, 3, 5, 8},
            new int[] {6, 7, 8, 9, 10},
            new int[] {1, 2, 3, 4, 5},
            new int[] {1, 2, 3, 4, 5},
            new int[] {1, 1, 1, 1, 1},
            new int[] {5, 5, 5, 5, 5},
            new int[] {1, 2, 3, 4, 5, 6},
            new int[] {1, 2, 3, 4, 5, 6},
            new int[] {1, 1, 2, 2, 3},
            new int[] {1, 2, 3}
        };
        for (int i = 0; i < testCases.Length; i++)
        {
            int[] result = HeapSort.Sort(testCases[i]);
            CollectionAssert.AreEqual(expectedResults[i], result);
        }
    }
}
#include <iostream>
#include <sstream>
#include <vector>
#include "heapSort.h"
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    // build heapify
    int left_index = 2 * root + 1;
    int right_index = 2 * root + 2;
    int largest_index = root;
    if (left_index < n && arr[largest_index] < arr[left_index])
    {
        largest_index = left_index;
    }

    if (right_index < n && arr[largest_index] < arr[right_index])
    {
        largest_index = right_index;
    }

    if (largest_index != root)
    {
        int temp = arr[root];
        arr[root] = arr[largest_index];
        arr[largest_index] = temp;

        heapify(arr, n, largest_index);
    }
}

// implementing heap sort
void heapSort(int arr[], int n)
{
    // build heap
    for (int i = n / 2; i > -1; i--)
    {
        heapify(arr, n, i);
    }

    // extracting elements from heap one by one
    for (int i = 0; i < n; i++)
    {
        int max = arr[0];

        arr[0] = arr[n - 1 - i];

        arr[n - 1 - i] = max;

        heapify(arr, n - i - 1, 0);
    }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// main program
void heapSortMain(vector<int> heap_arr)
{
    int n = heap_arr.size();

    heapSort(heap_arr.data(), n);

    displayArray(heap_arr.data(), n);
}
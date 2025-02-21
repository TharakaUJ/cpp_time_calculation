#include <iostream>
#include <vector>
#include "./quickSortIterative.h"

using namespace std;

int partitionIterative(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int pivotIndex = low;
    
    for(int i=low; i < high; i++) {
        if(arr[i] < pivot) {
            int temp = arr[i];
            arr[i] = arr[pivotIndex];
            arr[pivotIndex] = temp;
            
            pivotIndex++;
        }
    }
    
    arr[high] = arr[pivotIndex];
    arr[pivotIndex] = pivot;
    
    return pivotIndex;
}

void quickSortIterative(vector<int> &arr, int end) {
    vector<pair<int, int>> stack = {{0, end}};  // Stack stores (low, high) pairs

    while (!stack.empty()) {
        auto [low, high] = stack.back();
        stack.pop_back();

        if (low < high) {
            int pivotIndex = partitionIterative(arr, low, high);

            // Push subarrays to be sorted
            stack.push_back({low, pivotIndex - 1});
            stack.push_back({pivotIndex + 1, high});
        }
    }
}


void quickSortIterativeMain (vector<int> numbers) {
    int high = numbers.size()-1;
    
    quickSortIterative(numbers, high);
    
    for(int i:numbers) {
        cout << i << " ";
    }
}
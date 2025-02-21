#include <iostream>
#include <vector>
#include "./quickSortRecursive.h"

using namespace std;

int partitionRecursive(vector<int> &arr, int low, int high) {
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

void quickSortRecursive(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partitionRecursive(arr, low, high);
        
        quickSortRecursive(arr, low, pivotIndex-1);
        quickSortRecursive(arr, pivotIndex+1, high);
    }
}

void quickSortrecursiveMain (vector<int> numbers) {
   
    int high = numbers.size()-1;
    
    quickSortRecursive(numbers, 0, high);
    
    for(int i:numbers) {
        cout << i << " ";
    }
}
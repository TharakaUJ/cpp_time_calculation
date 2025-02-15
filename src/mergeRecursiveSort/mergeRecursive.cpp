#include <iostream>
#include <vector>
#include <limits>
#include "mergeRecursive.h"
#include "../merge.h"


using namespace std;

// void merge(vector<int> &arr, int left, int mid, int right) {
//     vector<int> leftArray;
//     vector<int> rightArray;
    
//     int inf = std::numeric_limits<int>::max();

    
//     for(int i = left; i < mid+1; i++) {
//         leftArray.push_back(arr[i]);
//     }
    
//     for(int i = mid+1; i < right+1; i++) {
//         rightArray.push_back(arr[i]);
//     }
    
//     leftArray.push_back(inf);
//     rightArray.push_back(inf);
    
//     int leftIndex = 0;
//     int rightIndex = 0;
//     int k = left;
    
//     while(k < right+1) {
//         if(leftArray[leftIndex] < rightArray[rightIndex]) {
//             arr[k] = leftArray[leftIndex];
//             leftIndex++;
//         }
//         else {
//             arr[k] = rightArray[rightIndex];
//             rightIndex++; 
//         }
//         k++;
//     }
// }

void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = (left+right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr,left,mid,right);
    }
}

void mergeSortRecursive(vector<int> &arr) {
    mergeSort(arr, 0, arr.size()-1);
}


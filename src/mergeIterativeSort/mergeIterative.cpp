#include <iostream>
#include <vector>
#include <limits>
#include "mergeIterative.h"
#include "../merge.h"

using namespace std;

void mergeSort(vector<int> &arr, int right) {
    int f = 1;
    
    while (f <= right) {
        for (int i = 0; i + f - 1 <= right; i += 2 * f) {
            int mid = i + f - 1;
            int end = min(i + 2 * f - 1, right);
            merge(arr, i, mid, end);
        }
        f *= 2;
    }
}

void mergeSortIterative(vector<int> &arr) {
    mergeSort(arr, arr.size()-1);
}
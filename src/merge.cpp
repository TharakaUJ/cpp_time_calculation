#include "merge.h"
#include <vector>
#include <limits>

void merge(std::vector<int> &arr, int left, int mid, int right)
{
    std::vector<int> leftArray;
    std::vector<int> rightArray;

    int inf = std::numeric_limits<int>::max();

    for (int i = left; i < mid + 1; i++)
    {
        leftArray.push_back(arr[i]);
    }

    for (int i = mid + 1; i < right + 1; i++)
    {
        rightArray.push_back(arr[i]);
    }

    leftArray.push_back(inf);
    rightArray.push_back(inf);

    int leftIndex = 0;
    int rightIndex = 0;
    int k = left;

    while (k < right + 1)
    {
        if (leftArray[leftIndex] < rightArray[rightIndex])
        {
            arr[k] = leftArray[leftIndex];
            leftIndex++;
        }
        else
        {
            arr[k] = rightArray[rightIndex];
            rightIndex++;
        }
        k++;
    }
}

#include <iostream>
#include <vector>
#include "optimizedBubble.h"

using namespace std;

int optimized_bubble_sort(vector<int> numbers) {
    int length_of_numbers = numbers.size();
    
    bool not_sorted = true;
    int i=1;
    
    while (not_sorted &&  i<length_of_numbers) {
        
        int j = 0;
        not_sorted = false;

        while (j < length_of_numbers) {
            if (numbers[j] > numbers[i]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
                not_sorted = true;
            }
            j++;
        }
        
        i++;
    }
    
    for(int i:numbers) {
        cout << i << " ";
    }
}
#include <iostream>
#include <vector>
#include "selection.h"

using namespace std;

int selection_sort(vector<int> numbers) {   
    int length_of_numbers = numbers.size();
    
    
    for (int i=0; i<length_of_numbers; i++) {
        int min_index = i;
        
        for (int j=i; j< length_of_numbers; j++) {
            if (numbers[j] < numbers[min_index]) {
               min_index = j;
            }
        }
        
        int temp = numbers[min_index];
        numbers[min_index] = numbers[i];
        numbers[i] = temp;
    }
    
    for(int i:numbers) {
        cout << i << " ";
    }
}
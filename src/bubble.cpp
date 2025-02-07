#include <iostream>
#include <vector>
#include "bubble.h"

using namespace std;

void bubble_sort(vector<int> numbers) {
    int length_of_numbers = numbers.size();
    
    
    for (int i=1; i<length_of_numbers; i++) {
        for (int j=0; j< length_of_numbers; j++) {
            if (numbers[j] > numbers[i]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    
    for(int i:numbers) {
        cout << i << " ";
    }
}
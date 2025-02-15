#include <iostream>
#include <vector>
#include "insertion.h"

using namespace std;

void insersion_sort(vector<int> numbers) {    
    int length_of_numbers = numbers.size();
    
    
    for (int i=1; i<length_of_numbers; i++) {
        
        int temp = numbers[i];
        
        int j = i-1;
        
          while (j >= 0 && numbers[j] > temp) {
            numbers[j + 1] = numbers[j];
            j = j - 1;
        }

        numbers[j+1] = temp;
    }
    
    for(int i:numbers) {
        cout << i << " ";
    }
}
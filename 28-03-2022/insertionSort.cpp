#include <iostream>

using namespace std;

void swap (int &a, int &b) {
    int temp = a;

    a = b;

    b = temp;
}

void selectionSort (int array[], int n) {
    int temp;

    for (int i = 1; i < n; i++) {
        temp = array[i];
        for (int j = i; j > 0; j--) {
            if (temp < array[j-1]) {
                array[j] = array[j-1];
            }
            else {
                break;
            }
            array[j] = temp;
        }
    }
}
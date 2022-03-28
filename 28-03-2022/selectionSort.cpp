#include <iostream>

using namespace std;

void swap (int &a, int &b) {
    int temp = a;

    a = b;

    b = temp;
}

void selectionSort (int array[], int n) {
    int indexMin;

    for (int i = 0; i < n; i++) {
        indexMin = i;
         for (int j = i+1; j < n; j++) {
            if (array[j] < array[indexMin]) {
                indexMin = j;
            }

            swap(array[i], array[indexMin]);
        }
    }
   
}

int main() {

    int array[] = {1, 2, 5, 4, 3, 6, 7, 8, 9, 10};


    cout << "Array ordinato [";
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    cout << "]";

    selectionSort(array, 10);

}
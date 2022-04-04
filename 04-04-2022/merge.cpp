#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>

using namespace std;

void merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    cout << "INDICI:" << p << " " << q << " " << r << endl;

    int *L = new int[n1 + 1];
    int *R = new int[n2 + 1];

    for (int i = 0; i < n1; i++) {
        L[i] = A[p+i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = A[q+j];
    }

    L[n1] = INT_MAX; // NUMERO MASSIMO INTERO (si usa con climits)
    R[n2] = INT_MAX; // NUMERO MASSIMO INTERO (si usa con climits)

    int i = 0, j = 0;

    for (int k = p; k < r; k++) {
        if (L[i] < R[j]) {
            A[k] = L[i];
            i++;
        } 
        else {
            A[k] = R[j];
            j++;
        }
    }

    delete [] L;
    delete [] R;
    
}

void mergesort(int A[], int p, int r) {
    if (p < r) {
        int q = floor((p + r) / 2.0);
        mergesort(A, p, q);
        mergesort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {

    int n = 100;

    int array[n];
    
    for (int i = 0; i < n; i++) {
        array[i] = rand()%1001;
    } 

    printArray(array, n);

    mergesort(array, 0, n);

    printArray(array, n);
}
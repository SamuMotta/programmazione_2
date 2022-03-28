#include <iostream>

using namespace std;

// ricerca binaria

bool ricercaBinaria(int array[], int n, int key) {
    bool found = false;

    int start = 0;
    int end = n-1;

    while(!found && (start != end)) {
        int midpoint = start + ((end - start) / 2); //float (n/2)

        cout << "start = " << start << ", end = " << end << ", midpoint = " << midpoint << endl;

        if (array[midpoint] == key) {
            found = true;
        }
        else if (key < array[midpoint]) { 
            //Considerare la metà inferiore
            //Aggiorniamo end e midpoint
            end = midpoint;
            //midpoint = (end-start)/2;
        }
        else { 
            //Considerare la metà superiore
            //Aggiornare start e midpoint

            start = midpoint+1;
            //midpoint = (end-start)/2;
        }

        cout<<"Start: " << start << endl;
    }
    return found;
        //verificare ad ogni iterazione se key >= array[n/2]

}

int main() {
    int vect[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    ricercaBinaria(vect, 10, 2);
}
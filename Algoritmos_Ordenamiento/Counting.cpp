#include <iostream>
using namespace std;

void countSort(int array[], int size) {

    int output[10];
    int count[10];
    int max = array[0];

    // hallamos el elemento mayor en el arreglo
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
        max = array[i];
    }

    // inicializamos sus elementos en cero
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // guardamos el conteo de cada elemento
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // y sus acumulativo
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

        // copiamos los elementos ordenados en el original
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

int main() {
     int array[] = {2,1,0,4,3};
    int n = 5;
    countSort(array, n);
    for(int i = 0; i < n; i++)
        cout<<array[i]<<" ";
    cout<<endl;
}
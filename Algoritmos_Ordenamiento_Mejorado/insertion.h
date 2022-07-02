#include<iostream>
using namespace std;

template<typename T>
void insertionSort(T arr[], int size, bool(*comparacion)(T,T)){

    int j;
    T num;
    for(int i = 1; i < size; i++){
        num = arr[i]; // asignamos el valor actual del array
        j = i-1; // j será el indice anterior (valor inicial : 0)

        // realizamos el traslado si el numero anterior es mayor
        while (j >= 0 && comparacion(num,arr[j])) {
            arr[j + 1] = arr[j];
            j--;
        }

        // completamos el intercambio
        arr[j + 1] = num;
        
    }
}

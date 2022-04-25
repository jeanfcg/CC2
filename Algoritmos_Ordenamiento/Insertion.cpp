#include<iostream>
using namespace std;

void insertionSort(int arr[], int lenght){
    int num, j;
    for(int i = 1; i < lenght; i++){
        num = arr[i]; // asignamos el valor actual del array
        j = i-1; // j será el indice anterior (valor inicial : 0)

        // realizamos el traslado si el numero anterior es mayor
        while (j >= 0 && arr[j] > num) {
            arr[j + 1] = arr[j];
            j--;
        }

        // completamos el intercambio
        arr[j + 1] = num;
        
        // imprimimos el resultado por cada el iteracion
        cout<<"Posicición: "<<i<<endl;
        for(int h = 0; h < lenght; h++) 
            cout<<arr[h]<<" ";
        cout<<endl;
    }
}

int main(){

    int arr[] = {2,1,0,4,3};
    insertionSort(arr,5);

    return 0;
}

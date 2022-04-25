#include <iostream>
using namespace std;

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {
  
  // Creamos dos subarreglos: Left y Right
  // Left ← Arr[p..q] and Middle ← A[q+1..r]

    int n1 = q - p + 1; // longitud L
    int n2 = r - q;     // longitud M

    int L[n1], M[n2];

    // copiamos los elementos en en los subarreglos
    for(int i = 0; i < n1; i++) 
        L[i] = arr[p + i];
    for(int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Se inician los iteradores
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // iteramos dentro de los subarreglos
    while (i < n1 && j < n2) {
        
        if (L[i] <= M[j]) {
            // itercambiamos valores
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        
        k++;
    }

    // escogemos los elementos sobrantes
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
  }
}

void mergeSort(int arr[], int size, int l, int r) {
  if (l < r) {
    // m es el punto medio entra los dos subarrays
    int m = l + (r - l) / 2;

    // lammamos a la funcion recursivamente tanto 
    // la mitad izquierda
    mergeSort(arr, size, l, m);
    // la mitad derecha
    mergeSort(arr, size,m + 1, r);


    for(int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
    
    cout<<endl;
    // unimos los arrays ordenados 
    merge(arr, l, m, r);
  }
}

int main() {
    int arr[] = {2,1,0,4,3},
    size = 5;

    mergeSort(arr, size, 0,size - 1);

    cout<<"\nResultado final:"<<endl;
    for(int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
    
    cout<<endl;

  return 0;
}
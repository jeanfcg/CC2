#include <iostream>
using namespace std;

template<typename T>
void quick(T arr[], int izq, int der, bool(*comparacion)(T,T))
{ 
    int i, j; 
    i = izq; 
    j = der; 

    T aux, x;
    x = arr[ (izq + der) /2 ];  // x será nuestro pivot

    do{ 

        while( comparacion(arr[i],x) && (j <= der) ) // realizamos comparaciones desde el pivot, y el extremo derechi
            i++;
 
        while( comparacion(x,arr[j]) && (j > izq) ) // realizamos comparaciones desde el pivoy, y el extremo izquierdo
            j--;
    
 
        if( i <= j ){  // realizamos un swap si es que llegan a ser iguales o aun no llegaron a ser iguales
            aux = arr[i]; 
            arr[i] = arr[j]; 
            arr[j] = aux; 
            i++;  
            j--; 
        }
         
    }while( i <= j ); 
 
    
    if( izq < j ) // funcion recursiva siempre y cuando aun no lleguen a los extremos
        quick( arr, izq, j , comparacion); 
    if( i < der ) 
        quick( arr, i, der ,comparacion); 

}

template <typename T>
void quickSort(T arr[], int size, bool(*comparacion)(T,T)){
    quick(arr,0,size-1,comparacion);
}
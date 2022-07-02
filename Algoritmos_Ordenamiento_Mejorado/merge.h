#include<iostream>
using namespace std;

template<typename T>
void merge(T arr[], int l, int m, int r, bool(*comparacion)(T,T)) {
   int nl, nr;

   nl = m - l + 1; // tamaño del array por izquierda
   nr = r - m; // tamaño del array por derecha

   T larr[nl], rarr[nr];

   //llenamos los arrays con los respectivos fragmentos
   for(int i = 0; i < nl; i++)
      larr[i] = arr[l + i];

   for(int j = 0; j < nr; j++)
      rarr[j] = arr[m +1 + j];


   int i = 0, j = 0, k = l;

   //comenzamos a pasar los valores desde los temporales al array principal
   while(i < nl && j < nr) {
      if(comparacion(larr[i],rarr[j])) { 
         arr[k] = larr[i];
         i++;
      }else{
         arr[k] = rarr[j];
         j++;
      }
      k++;
   }

   while(i < nl) {  // exlemento extra en el array izquierdo
      arr[k] = larr[i];
      i++; k++;
   }
   while(j < nr) {  // elemento extra en el array derecho
      arr[k] = rarr[j];
      j++; k++;
   }
}

template<typename T>
void merging(T arr[], int l, int r, bool(*comparacion)(T,T)) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Realizamos la primera division y lo mandamos a la funcion recursiva
      merging(arr, l, m, comparacion);
      merging(arr, m+1, r, comparacion);
      merge(arr, l, m, r, comparacion);
   }
}

template<typename T>
void mergeSort(T arr[], int size, bool(*comparacion)(T,T)){
   merging(arr,0,size-1,comparacion);
}
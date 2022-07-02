#include <iostream>
using namespace std;


void quicksort(int arr[],int izq, int der )
{ 
    int i, j, x , aux; 
    i = izq; 
    j = der; 
    x = arr[ (izq + der) /2 ]; 

    do{ 
        while( (arr[i] < x) && (j <= der) )
            i++;
 
        while( (x < arr[j]) && (j > izq) )
            j--;
    
 
        if( i <= j ){ 
            aux = arr[i]; 
            arr[i] = arr[j]; 
            arr[j] = aux; 
            i++;  
            j--; 
        }
         
    }while( i <= j ); 
 
    
    if( izq < j ) 
        quicksort( arr, izq, j ); 
    if( i < der ) 
        quicksort( arr, i, der ); 

}
 
int main () 
{
    
     int arr[] = {2,1,0,4,3};
     int n = 5;
    
    quicksort(arr,0,n-1);

    for(int i = 0; i < 5; i++)
        cout<<arr[i]<<" ";

    return 0;
   
}
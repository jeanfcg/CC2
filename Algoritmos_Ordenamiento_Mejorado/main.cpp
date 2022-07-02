#include"insertion.h"
#include"merge.h"
#include"quick.h"
#include"Point.h"
#include<iostream>
using namespace std;


template<typename T, typename U>
U getAnyValue(T * objeto,  U(T::*getter)(void)){
    return (objeto->*getter)();
}


bool operator<(string s1, string s2){
    return (s1.length() < s2.length());
}

bool operator>(string s1, string s2){
    return (s1.length() > s2.length());
}

template<typename T>
void mostrar(T arr[], int size){   
    for(int i = 0; i < size; i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
}


template<typename T>
bool ascendente(T a, T b){
    return b > a;
}

template<typename T>
bool descendente(T a, T b){
    return a > b;
}



template<typename T>
void ordenar(T arr[], int size){

    int opc;
    void (*ordenamiento)(T arr[], int size, bool(*comparacion)(T,T));

    cout<<"1. Insertion Sort"<<endl;
    cout<<"2. Quick Sort"<<endl;
    cout<<"3. Merge Sort"<<endl;
    cout<<"Digite que tipo de ordenamiento desea realizar: ";
    cin>>opc;

    switch (opc)
    {
        case 1: 
            cout<<"Insertion sort"<<endl;
            ordenamiento = insertionSort; 
        break;
        case 2: 
            cout<<"Quick sort"<<endl;
            ordenamiento = quickSort; 
        break;
        case 3: 
            cout<<"Merge sort"<<endl;
            ordenamiento = mergeSort; 
        break;
        default: break;
    }

    cout<<"1. Ascendente"<<endl;
    cout<<"2. Descendente"<<endl;
    cout<<"Desea ordenar ascendente o descendente? ";
    cin>>opc;

    bool (*comparacion)(T, T);

    if(opc == 1)  comparacion = ascendente;
    else comparacion = descendente;


    ordenamiento(arr,size,comparacion);
    mostrar(arr,size);
}




template<typename T, typename U>
void ordenar(T arr[], int size, U(T::*getter)(void)){
    U array[size];
    
    for(int i = 0; i < size; i++){
        array[i] = getAnyValue(&arr[i],getter);
    }

    ordenar(array,size);
}

int main(){

    int enteros[] = {4,4,3,6,1,2,7,3};
    string cadenas[] = {"Hola","Mundo","Como","Estan"};
    Point * puntos = new Point[5];


    for(int i = 0; i < 5; i++){
        puntos[i].setPoints(rand()%6 + 1, rand()%10 + 5);
        cout<<puntos[i].getX()<<"   "<<puntos[i].getY()<<endl;
    }

    cout<<endl;


    ordenar(puntos,5,&Point::getY);




    return 0;
}

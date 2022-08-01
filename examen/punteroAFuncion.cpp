#include<iostream>
using namespace std;

// funciones 
double suma(double a, double b){
    return a + b;
}

double resta(double a, double b){
    return a - b;
}

double multiplicar(double a, double b){
    return a * b;
}

// puntero a funcion
double funcion(double(*p)(double,double), double a, double b){
    return p(a,b);
}

int main(){

    double a = 6.7 , b = 8.9;

    cout<<"Suma: "<<funcion(suma,a,b)<<endl;
    cout<<"Resta: "<<funcion(resta,a,b)<<endl;
    cout<<"Multiplicacion: "<<funcion(multiplicar,a,b)<<endl;
    

    return 0;
}
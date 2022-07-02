#include<iostream>
using namespace std;

int mayor(int a, int b){
    if(a > b) return a;
    return b;
}

int menor(int a, int b){
    if(a < b) return a;
    return b;
}


void func( int(*p)(int,int) , int a , int b){
    p(a,b);
}

int main(){

    int a = 5, b = 6;
    int(*p)(a,b) = mayor;


    return 0;
}
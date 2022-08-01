#include<iostream>
using namespace std;

void duplicarMatriz(int x[][3][3], int dim_i, int dim_j, int dim_k){
    for(int i = 0; i < dim_i; i++)
        for(int j = 0; j < dim_j; j++)
            for(int k = 0; k < dim_k; k++)
                // iteramos y lo duplicamos x 2
                *(*(* (x + i) + j) + k) *= 2;
}


void mostrarMatriz(int x[][3][3], int dim_i, int dim_j, int dim_k){
    for(int i = 0; i < dim_i; i++)
        for(int j = 0; j < dim_j; j++)
            for(int k = 0; k < dim_k; k++)
                // mostramos usando los iteradores
                cout<<*(*(* (x + i) + j) + k)<<endl;
}


int main(){

    // matriz x : tridimensional
    int x[3][3][3] = {
        {{1,2,3},{4,5,6},{7,8,9}},
        {{11,12,13},{14,15,16},{17,18,19}},
        {{21,22,23},{24,25,26},{27,28,29}}
    };

    mostrarMatriz(x,3,3,3);
    cout<<endl;
    duplicarMatriz(x,3,3,3);
    mostrarMatriz(x,3,3,3);

    return 0;
}
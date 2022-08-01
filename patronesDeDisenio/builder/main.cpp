#include<iostream>
using namespace std;

#include"Director.h"
#include"Builder.h"
#include"BuilderEspecifico.h"

void construcciones(Director &director){
    BuilderEspecifico* builder = new BuilderEspecifico();
    director.setBuilder(builder);

    cout<<"Cimientos de la casa: "<<endl; 
    director.ConstruirCimientos();
    Producto * p = builder->getProducto();
    p->ListaComp();
    delete p;

    cout<<endl<<"Casa techada: "<<endl; 
    director.ConstruirCasaTechada();
    p = builder->getProducto();
    p->ListaComp();
    delete p;

    cout<<endl<<"Casa terminada: "<<endl; 
    director.ConstruirCasaTerminada();
    p = builder->getProducto();
    p->ListaComp();
    delete p;
}

int main(){

    Director * director = new Director;
    construcciones(*director);
    delete director;

    return 0;
}
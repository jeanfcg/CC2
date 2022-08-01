#include<iostream>

#include"AbstractFactory.h"
#include"Factorys.h"

using namespace std;

void Cliente(const AbstractFactory& f) {
    const AbstractModernProduct* productoA = f.CrearProductoModerno();
    const AbstractOldProduct* productoB = f.CrearProductoAntiguo();
    cout << productoA->mueble() << "\n";
    cout << productoB->mueble() << "\n";
    delete productoA;
    delete productoB;
}

int main() {

    cout<<"Sofas: "<<endl;
    Factory1 * f1 = new Factory1();
    Cliente(*f1);
    delete f1;

    cout<<endl;
    cout<<"Mesas: "<<endl;
    Factory2 * f2 = new Factory2();
    Cliente(*f2);
    delete f2;

    return 0;
}
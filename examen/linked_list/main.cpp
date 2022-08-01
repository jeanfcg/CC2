#include"Node.cpp"
#include"LinkedList.cpp"

#include<iostream>
using namespace std;

int main(){
    LinkedList lista1(14);
    LinkedList lista2(15);
    LinkedList lista3;
    lista3 = lista1 + lista2;

    cout << lista3 << endl;
    return 0;
}
#include<iostream>
#include <ostream>
#include <typeinfo>
using namespace  std;

long int potencia(int base, int exponente){
  long int p = 1;
  for(int i = 0; i < exponente; i++)
    p *= base;
  return p;
}

void f(const int arr[])
{
  arr[0] = 10;
}

int main(){

/*
  char c;
  cout<<"Digite un caracter: " ;
  cin>> c;

  int val = static_cast <int> (c);
  string texto = ((val >= 65 && val <= 90) || (val >= 97 && val <= 122)) ? "Es una letra" : "NO es una letra";

  cout<<texto<<endl;
*/
  cout<<potencia(2,8)<<endl;

  int x;
  cout<<"Numero: ";cin>>x;
  int arr[x];

  
  return 0;
}


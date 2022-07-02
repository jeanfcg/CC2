#include<iostream>
using namespace std;

int *getprt(){
  int *x = new int;
  *x = 5;
  return x;
}

int main(){
  
  int *p = getprt();
  cout<<*p<<endl;
  
  return 0;
}

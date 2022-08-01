#include<iostream>
#include<set>
using namespace std;

int main(){

    set<int> numeros = {1,2,3,4};
    auto it = begin(numeros);

    cout<<typeid(*it).name();

    return 0;
}
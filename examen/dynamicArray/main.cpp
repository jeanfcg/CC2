#include<iostream>
#include"DynamicArray.h"
#include"Persona.h"
#include"Docente.h"
#include"Estudiante.h"
using namespace std;

std::ostream& operator <<(std::ostream &output, const Persona &persona) {
    output << persona.toString();
    return output;
}


int main(){


    Persona **personas = new Persona*[5];
    personas[0] = new Docente("Sergio", 18);
    personas[1] = new Docente("Sebastian", 90);
    personas[2] = new Estudiante("Lucho", 18);
    personas[3] = new Estudiante("Miranda", 31);
    personas[4] = new Estudiante("Sonia", 87);

    DynamicArray<Persona*> da(personas, 5);
    std::cout << da << std::endl;

    return 0;
}
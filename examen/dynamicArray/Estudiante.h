#ifndef _ESTUDIANTE_H_
#define _ESTUDIANTE_H_

#include"Persona.h"

class Estudiante : public Persona
{
private:
public:
    Estudiante(std::string n, int e) : Persona(n,e){}
    ~Estudiante();
    std::string toString() const override {
        return getNombre() + " es un estudiante y tiene " + std::to_string(getEdad()) + " años. ";
    }
};



#endif
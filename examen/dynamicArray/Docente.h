#ifndef _DOCENTE_H_
#define _DOCENTE_H_

#include"Persona.h"

class Docente : public Persona
{
private:
public:
    Docente(std::string n, int e) : Persona(n,e){}
    ~Docente();
    std::string toString() const override {
        return getNombre() + " es un docente y tiene " + std::to_string(getEdad()) + " años. ";
    }
};



#endif
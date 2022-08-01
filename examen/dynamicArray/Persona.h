#ifndef _PERSONA_H_
#define _PERSONA_H_

#include<string>

class Persona
{
private:
    std::string nombre;
    int edad;
public:
    Persona(std::string n, int e) : nombre(n), edad(e){}
    ~Persona();
    virtual std::string toString() const = 0;
    std::string getNombre() const {return nombre;}
    int getEdad() const {return edad;}


};

#endif
#ifndef DIRECTOR
#define DIRECTOR

#include"Builder.h"

class Director {
private:
    Builder* builder;
public:
    void setBuilder(Builder* builder){
        this->builder = builder;
    }

    void ConstruirCimientos(){
        this->builder->ProducirParedes();
        this->builder->ProducirColumnas();
    }

    void ConstruirCasaTechada(){
        ConstruirCimientos();
        this->builder->ProducirTecho();
    }

    void ConstruirCasaTerminada(){
        ConstruirCasaTechada();
        this->builder->ProducirPuertas();
        this->builder->ProducirVentanas();
    }
};

#endif
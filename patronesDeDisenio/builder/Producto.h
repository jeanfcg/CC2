#ifndef PRODUCTO
#define PRODUCTO

#include<vector>
#include<iostream>

class Producto
{
public:
    std::vector<std::string> componentes;

    void ListaComp() const {
        std::cout << "Partes construidas de la casa: ";
        for(size_t i = 0; i < componentes.size(); i++){
            if(componentes[i] == componentes.back())
                std::cout << componentes[i] << std::endl;
            else 
                std::cout << componentes[i] << ", ";
        }
    }
};

#endif
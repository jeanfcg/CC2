#ifndef FACTORY
#define FACTORY

#include"AbstractModernProduct.h"
#include"AbstractOldProduct.h"

class AbstractFactory {
public:
    virtual AbstractModernProduct* CrearProductoModerno() const = 0;
    virtual AbstractOldProduct* CrearProductoAntiguo() const = 0;
};

#endif


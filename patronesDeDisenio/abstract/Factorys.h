#include"AbstractFactory.h"
#include "ModernProducts.h"
#include "OldProducts.h"

#ifndef FACTORY_1
#define FACTORY_1

class Factory1 : public AbstractFactory {
public:
    AbstractModernProduct* CrearProductoModerno() const override {
        return new sofaModerno();
    }
    
    AbstractOldProduct* CrearProductoAntiguo() const override {
        return new sofaAntiguo();
    }
};

#endif

#ifndef FACTORY_2
#define FACTORY_2

class Factory2 : public AbstractFactory {
public:
    AbstractModernProduct* CrearProductoModerno() const override {
        return new mesaModerna();
    }

    AbstractOldProduct* CrearProductoAntiguo() const override {
        return new mesaAnitigua();
    }
};

#endif
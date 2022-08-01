#include"AbstractModernProduct.h"

#ifndef MODERN_PRODUCT_1
#define MODERN_PRODUCT_1

class sofaModerno : public AbstractModernProduct {
    public:
    std::string mueble() const override {
        return "Es un sofa con calefaccion";
    }
};


#endif


#ifndef MODERN_PRODUCT_2
#define MODERN_PRODUCT_2

class mesaModerna : public AbstractModernProduct {
    std::string mueble() const override {
        return "Es una mesa con pantalla tactil";
    }
};

#endif
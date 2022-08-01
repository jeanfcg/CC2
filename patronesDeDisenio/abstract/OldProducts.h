#include"AbstractOldProduct.h"

#ifndef OLD_PRODUCT_1
#define OLD_PRODUCT_1

class sofaAntiguo : public AbstractOldProduct {
    public:
    std::string mueble() const override {
        return "Es un sofa de la epoca victoriana";
    }
};


#endif


#ifndef OLD_PRODUCT_2
#define OLD_PRODUCT_2

class mesaAnitigua : public AbstractOldProduct {
    std::string mueble() const override {
        return "Es una mesa de madera comun";
    }
};

#endif
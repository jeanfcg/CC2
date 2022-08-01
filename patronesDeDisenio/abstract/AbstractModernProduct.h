#ifndef MODERN_PRODUCT
#define MODERN_PRODUCT

#include<iostream>

class AbstractModernProduct {
public:
    virtual ~AbstractModernProduct() {};
    virtual std::string mueble() const = 0;
};

#endif


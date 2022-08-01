#ifndef OLD_PRODUCT
#define OLD_PRODUCT

#include<iostream>

class AbstractOldProduct {
public:
    virtual ~AbstractOldProduct() {};
    virtual std::string mueble() const = 0;
};

#endif
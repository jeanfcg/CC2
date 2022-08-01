#ifndef BUILDER
#define BUILDER

class Builder
{
public:
    virtual ~Builder(){}
    virtual void ProducirParedes() const = 0;
    virtual void ProducirColumnas() const = 0;
    virtual void ProducirTecho() const = 0;
    virtual void ProducirPuertas() const = 0;
    virtual void ProducirVentanas() const = 0;
};

#endif

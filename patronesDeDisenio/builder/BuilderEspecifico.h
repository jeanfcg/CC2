#ifndef BUILDER_ESPECIFICO
#define BUILDER_ESPECIFICO

#include"Producto.h"
#include"Builder.h"

class BuilderEspecifico : public Builder
{
private:
    Producto * product;
public:
    BuilderEspecifico(){
        this->Reset();
    }

    ~BuilderEspecifico(){
        delete product;
    }

    void Reset(){
        this->product = new Producto();
    }

    void ProducirParedes() const override {
        this->product->componentes.push_back("Paredes");
    }
    void ProducirColumnas() const override {
        this->product->componentes.push_back("Columnas");
    }
    void ProducirTecho() const override {
        this->product->componentes.push_back("Techo");
    }

    void ProducirPuertas() const override {
        this->product->componentes.push_back("Puertas");
    }

    void ProducirVentanas() const override {
        this->product->componentes.push_back("Ventanas");
    }

    Producto * getProducto(){
        Producto * resultado = this->product;
        this->Reset();
        return resultado;
    }
};

#endif
#include"carta.h"


Carta::Carta(){

    txt_reverso = new Texture;
    spt_reverso = new Sprite;
 
    txt_reverso->loadFromFile("images/reversoCartaPokemon.jpg");
    spt_reverso->setTexture(*txt_reverso);
    spt_reverso->setScale({0.7,0.7});
}

Carta::~Carta(){}

Sprite Carta::getSprite(){
    return *spt_reverso;
}

void Carta::setPosicion(Vector2f posicion){
    const int margenLateral = 60;
    const int margenSuperior = 50;

    posicion.x *= 150;
    posicion.y *= 200;

    posicion.x += margenLateral;
    posicion.y += margenSuperior;

    spt_reverso->setPosition(posicion);
}



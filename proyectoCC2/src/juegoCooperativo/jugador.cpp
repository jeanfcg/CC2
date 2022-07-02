#include"jugador.h"
using namespace sf;


Jugador::Jugador(){
    imagen.loadFromFile("images/yugi.png");
    sprite.setTexture(imagen);
    sprite.setScale({0.25,0.25});
    sprite.setPosition({0,300});

    velocidad.x = 0;
    velocidad.y = -30; // este es el impulso

    aceleracion.x = 0;
    aceleracion.y = 9.81; // esta es la gravedad con la que cae
}

Sprite Jugador::getSprite(){
    return sprite;
}

void Jugador::move(Vector2f movimientos){
    movimientos.x += sprite.getPosition().x;
    movimientos.y += sprite.getPosition().y;

    sprite.setPosition(movimientos);
}

void Jugador::caida(float delta_t){
    delta_t /= 10;

    velocidad.x = aceleracion.x * delta_t;
    velocidad.y += aceleracion.y * delta_t;

    move({velocidad.x * delta_t, velocidad.y * delta_t});
}

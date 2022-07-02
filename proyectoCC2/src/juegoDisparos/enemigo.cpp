#include"enemigo.h"
using namespace std;

Enemigo::Enemigo(Vector2f posicion){

    int numeroEnemigo;
    numeroEnemigo = rand() % 3 + 1;

    string path;
    path = "images/zombie" + to_string(numeroEnemigo) + ".png";

    txtr_monster.loadFromFile(path);
    sprt_monster.setTexture(txtr_monster);
    sprt_monster.setScale({0.3,0.3});
    sprt_monster.setPosition(posicion);
    
    reloj1 = new Clock;
    tiempo1 = new Time;

    *tiempo1 = reloj1->getElapsedTime();
}

Sprite Enemigo::getSprite(){
    return sprt_monster;
}

float Enemigo::getSeconds(){
    *tiempo1 = reloj1->getElapsedTime();
    return tiempo1->asSeconds();
}
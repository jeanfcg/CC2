#include<SFML/Graphics.hpp>
#include"juego.cpp"
using namespace sf;

int main(){

    // ese arreglo es de tipo: "vector2f"
    Juego *partida1;
    partida1 = new Juego({800,600},"hola mundo");


    return 0;
}
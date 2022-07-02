#include"juego.h"
using namespace std;

juego::juego(int resolucion_x, int resolucion_y, string titulo){
    fps = 60;
    ventana = new RenderWindow(VideoMode(resolucion_x,resolucion_y),titulo);
    ventana->setFramerateLimit(fps);

    textura1 = new Texture;
    sprite1 = new Sprite;

    textura1->loadFromFile("images/imagen.png");
    sprite1->setTexture(*textura1);

    gameLoop();
}

void juego::dibujar(){
    ventana->clear();
    ventana->draw(*sprite1);
    ventana->display();
}

void juego::gameLoop(){
    while (ventana->isOpen()){
        dibujar();
    }
    
}
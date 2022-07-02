#include"juego.h"
#include<iostream>
using namespace std;


Juego::Juego(){
    gameOver = false;
    ventana = new RenderWindow(VideoMode(800,600),"Hola");
    jugador1 = new Jugador();
    evento = new Event;

    reloj1 = new Clock;
    tiempo1 = new Time;

    gameloop();
}


void Juego::gameloop(){
    while (!gameOver){
        *tiempo1 = reloj1->getElapsedTime();
        ventana->clear(Color::Green);
        procesar_eventos();
        //jugador1->caida(tiempo1->asSeconds());

        ventana->draw(jugador1->getSprite());
        ventana->display();
    }    
}

void Juego::procesar_eventos(){
    while (ventana->pollEvent(*evento)){
        switch (evento->type){

            // necesario para cerrar la ventana correctamente
            case Event::Closed:
                ventana->close();
                exit(1);
            break;

            case Event::KeyPressed:
                if(Keyboard::isKeyPressed(Keyboard::Right))
                    jugador1->move({10,0}); // 10 a la derecha, 0 de subida
                else if(Keyboard::isKeyPressed(Keyboard::Left))
                    jugador1->move({-10,0});
                else if(Keyboard::isKeyPressed(Keyboard::Up))
                    jugador1->caida(tiempo1->asSeconds());
                else if(Keyboard::isKeyPressed(Keyboard::Down))
                    jugador1->move({0,10});

            break;        
        }
    }
    
}

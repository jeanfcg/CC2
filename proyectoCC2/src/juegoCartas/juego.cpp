#include"juego.h"
#include<iostream>
using namespace std;

Juego::Juego(Vector2f dimensiones,Vector2f tablero,string titulo){
    this->tablero = tablero;
    ventana1 = new RenderWindow(VideoMode(dimensiones.x,dimensiones.y),titulo);
    gameOver = false;

    cartas = new Carta * [(int)tablero.x];
    for(int i = 0; i < (int)tablero.x; i++){
        cartas[i] = new Carta[(int)tablero.y];
    }

    evento = new Event;
    gameloop();
}

void Juego::gameloop(){
    while (!gameOver){
        ventana1->clear();
                
        for(int i = 0; i < (int)tablero.x; i++){
            for(int j = 0; j < (int)tablero.y; j++){
                cartas[i][j].setPosicion({(float)i,(float)j});
                ventana1->draw(cartas[i][j].getSprite());
            }
        }

        procesarEventos();
        ventana1->display();
    }
    
}

void Juego::procesarEventos(){
    while(ventana1->pollEvent(*evento)){
        switch(evento->type){
            case Event::MouseButtonPressed:{
                Vector2f punto = (Vector2f)Mouse::getPosition(*ventana1);
                //cout<<punto.x<<"    "<<punto.y<<endl;
                
                for(int i = 0; i < (int)tablero.x; i++){
                    for(int j = 0; j < (int)tablero.y; j++){
                        if(cartas[i][j].getSprite().getLocalBounds().contains(punto)){
                            float left =  cartas[i][j].getSprite().getLocalBounds().left;
                            float top =  cartas[i][j].getSprite().getLocalBounds().top;
                            cout<<left<<"     "<<top<<endl;
                        }
                    }
                }
            }

            break;
        }
    }   
}
#include"juego.h"
using namespace std;

Juego::Juego(Vector2f resolucion, string title){
    gameOver = false;   
    fps = 60;

    ventana1 = new RenderWindow(VideoMode(resolucion.x,resolucion.y),title);
    ventana1->setFramerateLimit(fps);

    for(int i = 0; i < 4; i++)
        slots_monsters[i] = false;
    
    //mouse
    ventana1->setMouseCursorVisible(false);
    evento1 = new Event;

    reloj1 = new Clock;
    tiempo1 = new Time;
    tiempo2 = 0;

    cargar_graficos();
    gameLoop();
}


void Juego::gameLoop(){

    
    while (!gameOver){
    
        *tiempo1 = reloj1->getElapsedTime();

        if(tiempo1->asSeconds() > 5 + tiempo2){
            tiempo2 = tiempo1->asSeconds();
            int resultado;
            resultado = rand() % 100 + 1;

            if(resultado < 30){
                // no crreamos monstruo
            }else{
                // creamos monstruo
                bool espacioDisponible = false;
                for(int i = 0; i < 4; i++){
                    if(!slots_monsters[i]){
                        espacioDisponible = true;
                        break;
                    }
                }
                if(espacioDisponible == true){
                    while(true){
                        int resultado = rand() % 3 + 0;
                        if(slots_monsters[resultado] == false){
                            monsters[resultado] = new Enemigo({(float)200*resultado,300});
                        }
                            break;
                    }
                }
            }
        }

        checkear_enemigos();

        ventana1->clear();

        procesarEventos();

        ventana1->draw(sprt_fondo);

        for(int i = 0; i < 4; i++){
            if(monsters[i] != NULL){
                ventana1->draw(monsters[i]->getSprite());
            }
        }

        ventana1->draw(sprt_mira);

        ventana1->display();
    }    
}

void Juego::cargar_graficos(){

    txtr_fondo.loadFromFile("images/background.jpg");
    sprt_fondo.setTexture(txtr_fondo);
    sprt_fondo.setScale(
        (float)(ventana1->getSize().x)/txtr_fondo.getSize().x,
        (float)(ventana1->getSize().y)/txtr_fondo.getSize().y
    );

    txtr_mira.loadFromFile("images/mira.png");
    sprt_mira.setTexture(txtr_mira);
    sprt_mira.setScale({0.2,0.2});
}

void Juego::procesarEventos(){
    while(ventana1->pollEvent(*evento1)){
        switch(evento1->type){
            case Event::MouseMoved:
                sprt_mira.setPosition((Vector2f)Mouse::getPosition(*ventana1));
            break;
            case Event::MouseButtonPressed:
                FloatRect recta(sprt_mira.getPosition(),(Vector2f)sprt_mira.getTexture()->getSize());

                for(int i = 0; i < 4; i++){
                    if(monsters[i]){
                        // colision
                        if(monsters[i]->getSprite().getGlobalBounds().intersects(recta)){
                            monsters[i] = NULL;
                        }
                    }
                }
            break;
        }
    }
}

void Juego::checkear_enemigos(){
    for(int i = 0; i < 4; i++){
        if(monsters[i]){
            if(monsters[i]->getSeconds() > 6){
                monsters[i] = NULL;
            }
        }
    }
}
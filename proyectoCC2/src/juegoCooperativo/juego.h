#include<SFML/Graphics.hpp>
#include"jugador.cpp"
using namespace sf;

class Juego
{
    private:
        bool gameOver;
        RenderWindow * ventana;
        Jugador * jugador1;
        Event * evento;

        Clock * reloj1;
        Time * tiempo1;
    public:
        Juego(/* args */);
        ~Juego();
        void gameloop();
        void procesar_eventos();
};

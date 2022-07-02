#include<SFML/Graphics.hpp>
#include"carta.cpp"
using namespace sf;
using namespace std;

class Juego
{
    private:
        RenderWindow * ventana1;        
        bool gameOver;
        Carta **cartas;
        Vector2f tablero; // m x n, del numero de cartas del tablero
        Event * evento;
    public:
        Juego(Vector2f dimensiones,Vector2f tablero,string titulo);
        ~Juego();
        void gameloop();
        void procesarEventos();
};


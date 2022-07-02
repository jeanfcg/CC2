#include <SFML/Graphics.hpp>
#include"juego.cpp"
using namespace sf;
using namespace std;

int main()
{
    juego *partida;
    partida = new juego(800,600,"hola mundo");

    return 0;
}
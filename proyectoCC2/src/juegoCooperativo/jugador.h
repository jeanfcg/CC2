#include<SFML/Graphics.hpp>
using namespace sf;

class Jugador
{
    private:
        Texture imagen;
        Sprite sprite;

        Vector2f velocidad;
        Vector2f aceleracion; 

    public:
        Jugador(/* args */);
        ~Jugador();
        Sprite getSprite();
        void move(Vector2f movimiento);
        void caida(float delta_t); // la caida libre
};


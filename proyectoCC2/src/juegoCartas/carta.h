#include<SFML/Graphics.hpp>
using namespace sf;

class Carta
{
    private:
        Texture * txt_reverso;
        Sprite * spt_reverso;
    public:
        Carta();
        ~Carta();
        Sprite getSprite();
        void setPosicion(Vector2f posicion);
};


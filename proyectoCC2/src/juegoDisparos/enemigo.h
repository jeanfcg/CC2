#include<SFML/Graphics.hpp>
using namespace sf;

class Enemigo
{
    private:
        Texture txtr_monster;
        Sprite sprt_monster;
        Clock * reloj1;
        Time * tiempo1;
    public:
        Enemigo(Vector2f posicion);
        ~Enemigo();
        Sprite getSprite();
        float getSeconds();
};

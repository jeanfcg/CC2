#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class juego{
    private:
        RenderWindow * ventana;
        int fps;
        Texture * textura1;
        Sprite * sprite1;
    public:
        juego(int resolucion_x, int resolucion_y, string titulo);
        ~juego();
        void dibujar();
        void gameLoop();
};


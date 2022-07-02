#include<SFML/Graphics.hpp>
#include"enemigo.cpp"
using namespace sf;
using namespace std;

class Juego
{
    private:
        bool gameOver;
        RenderWindow * ventana1;
        int fps;

        bool slots_monsters[4];

        //texturas y sprites
        Texture txtr_fondo;
        Sprite sprt_fondo;

        Texture txtr_mira;
        Sprite sprt_mira;

        // eventos
        Event * evento1;

        //enemigos
        Enemigo * monsters[4];

        //reloj
        Clock * reloj1;
        Time * tiempo1;
        float tiempo2;
        

    public:
        Juego(Vector2f resolucion, string title);
        ~Juego();
        void gameLoop();
        void cargar_graficos();
        void procesarEventos();
        void checkear_enemigos();
};


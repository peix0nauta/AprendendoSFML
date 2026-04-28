#include "tiro.h"
#include "jogador.h"
#include "mapa.h"
#include <SFML/Graphics.hpp>

class Game{
    private:
        std::vector<Projetil> balas;
        Player jogador;
        sf::RenderWindow window;
        sf::View camera;
        Mapa map;
        void ProcessarEventos();
        void Atualizar();
        void Renderizar();

    public:
        Game();
        void Rodar();


};
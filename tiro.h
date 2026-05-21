#pragma once
#include <SFML/Graphics.hpp>

class Projetil{
    private:
        sf::ConvexShape triangulo;
        float velo;
        int dir;
    public:

        Projetil(float x, float y,int dire);
        ~Projetil();
        void movebala();
        sf::Vector2f getPosicao() const;
        void desenhar(sf::RenderWindow& window);

};
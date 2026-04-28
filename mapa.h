#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Mapa {
private:
    float alturaBloco = 60.f;
    float larguraBloco = 80.f;
    int grade[10][10];
    
    sf::RectangleShape bloco;



public:
    Mapa();
    void desenhar(sf::RenderWindow& window);
    bool Colisao(sf::Vector2f posicao);
};
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Mapa {
private:
    static const int LINHAS=12,
                     COLUNAS=100;
    float alturaBloco = 50.f;
    float larguraBloco = 50.f;
    int grade[LINHAS][COLUNAS];
    
    sf::RectangleShape bloco;



public:
    Mapa();
    void desenhar(sf::RenderWindow& window);
    bool Colisao(sf::Vector2f posicao);
};
#include "mapa.h"
#include <SFML/Graphics.hpp>

Mapa::Mapa() {


int valores[10][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grade[i][j] = valores[i][j];
        }
    }

    bloco.setSize({larguraBloco, alturaBloco});
}

void Mapa::desenhar(sf::RenderWindow& window) {
    for (int i = 0; i < 10; i++) {       
        for (int j = 0; j < 10; j++) {     
            
            if (grade[i][j] == 1) {
                bloco.setFillColor(sf::Color::White); // Parede
                bloco.setPosition({j * larguraBloco, i * alturaBloco});
                window.draw(bloco);
            }

        }
    }
}


bool Mapa::Colisao(sf::Vector2f posicao){

    int coluna = static_cast<int>(posicao.x / larguraBloco);
    int linha = static_cast<int>(posicao.y / alturaBloco);

    if (linha < 0 || linha >= 10 || coluna < 0 || coluna >= 10) {
        return true; 
    }
 
    return grade[linha][coluna]==1;
}



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

    bloco.setSize({80.f, 60.f});
}

void Mapa::desenhar(sf::RenderWindow& window) {
    for (int i = 0; i < 10; i++) {         // Linhas (Y)
        for (int j = 0; j < 10; j++) {     // Colunas (X)
            
            if (grade[i][j] == 1) {
                bloco.setFillColor(sf::Color::White); // Parede
                bloco.setPosition({j * 80.f, i * 60.f});
                window.draw(bloco);
            }
            // Se for 0, não desenhamos nada (fica o fundo preto)
        }
    }
}
#include <SFML/Graphics.hpp>
#include <optional>
#include <vector>
#include <algorithm>
#include "jogo.h"


Game::Game() : window(sf::VideoMode({800, 600}), "Meu Jogo UTFPR") {
    window.setFramerateLimit(60); 

}

void Game:: Atualizar(){

    jogador.gerenciarMovimentacao(map);

    jogador.atirar(balas);
    jogador.trocaCor();

    for (auto& b : balas) {
        b.movebala(); 
    }
    balas.erase(std::remove_if(balas.begin(), balas.end(), [](const Projetil& b) {
        sf::Vector2f pos = b.getPosicao();
        return (pos.x < 0 || pos.x > 800 || pos.y < 0 || pos.y > 600);
    }), balas.end());
}

void Game::Renderizar() {
    window.clear();

    map.desenhar(window);
    jogador.desenhar(window); 
    
    for (auto& b : balas) {
        b.desenhar(window);   
    }

    window.display();
}
void Game::ProcessarEventos() {

    while (const std::optional event = window.pollEvent()) {
        
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }
}

void Game::Rodar() {
    while (window.isOpen()) {
        ProcessarEventos();
        Atualizar();
        Renderizar();
    }
}
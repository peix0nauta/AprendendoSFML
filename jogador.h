#pragma once
#include <SFML/Graphics.hpp>
#include "tiro.h"

class Player {
private:
    sf::CircleShape corpo;
    float velocidade;

public:
    Player(); // Este é o "inicializa" automático (Construtor)
    void gerenciarMovimentacao();
    void desenhar(sf::RenderWindow& window);
    void trocaCor();
    void atirar(std::vector<Projetil>& listaDeBalas);

    
};


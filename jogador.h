#pragma once
#include <SFML/Graphics.hpp>
#include "tiro.h"
#include "mapa.h"
class Player {
private:
    sf::CircleShape corpo;
    float velocidade;
    int raio;

public:
    Player(); // Este é o "inicializa" automático (Construtor)
    void gerenciarMovimentacao(Mapa& map);
    void desenhar(sf::RenderWindow& window);
    void trocaCor();
    void atirar(std::vector<Projetil>& listaDeBalas);

    
};


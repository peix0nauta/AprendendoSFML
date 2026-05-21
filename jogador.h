#pragma once
#include <SFML/Graphics.hpp>
#include "tiro.h"
#include "mapa.h"
class Player {
private:
    sf::CircleShape corpo;
    float velocidade;
    int raio;
    sf::Clock relogioTiro,relogioPulo; 
    float tempoRecarga,tempoPulo;
    float yInicial ;
    bool pulou;
public:
    Player(); // Este é o "inicializa" automático (Construtor)
    void gerenciarMovimentacao(Mapa& map);
    void desenhar(sf::RenderWindow& window);
    void trocaCor();
    void atirar(std::vector<Projetil>& listaDeBalas);
    sf::Vector2f getPosiçao();
    void setyInicial(float y) { yInicial = y; }
};


#include "jogador.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

// O Construtor faz o papel da função 'inicializar'
Player::Player() {
    corpo.setRadius(12.f);
    corpo.setFillColor(sf::Color::Blue);
    corpo.setPosition({400.f, 300.f});
    velocidade = 5.0f;
    raio = 12;
    tempoRecarga=0.5f;
    tempoPulo=1.5f;
    yInicial = 0.f;
    pulou = false;
}

sf::Vector2f Player::getPosiçao(){
    sf::Vector2f pos =  corpo.getPosition();
    return pos;
}



void Player::gerenciarMovimentacao(Mapa& map) {

    sf::Vector2f pos =  corpo.getPosition();



    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && !pulou) {
        pulou = true;
        relogioPulo.restart(); 
        setyInicial(pos.y); // Salve a posição do chão
    }

    
    if (pulou) {
        
                // Transforma o tempo em uma escala de 0.0 (início) a 1.0 (fim do pulo)
        float progresso = relogioPulo.getElapsedTime().asSeconds() / tempoPulo;
        
        if (progresso < 1.0f) {
                    // Fórmula de parábola suave: 4 * altura * x * (1 - x)
                float alturaMaxima = 150.f; // Quantos pixels de altura você quer que ele pule
                float alturaAtual = 4.f * alturaMaxima * progresso * (1.0f - progresso);

                    // Define a nova posição com base no Y inicial
                corpo.setPosition({pos.x, yInicial - alturaAtual});
                } 
        else {
                    // O tempo acabou, garante que ele volte exatamente para o chão
            corpo.setPosition({pos.x, yInicial});
            pulou = false;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
        if(!map.Colisao({pos.x, pos.y - velocidade+raio*2}))
            corpo.move({0.f, velocidade});
        else    
            corpo.move({0.f,-velocidade});
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        if(!map.Colisao({pos.x, pos.y - velocidade}))
            corpo.move({-velocidade, 0.f});
        else    
            corpo.move({+velocidade, 0.f});
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        if(!map.Colisao({pos.x+raio*2, pos.y - velocidade}))
            corpo.move({velocidade, 0.f});
        else
            corpo.move({-velocidade, 0.f});
    }

}

void Player::desenhar(sf::RenderWindow& window) {
    window.draw(corpo);
}

void Player::trocaCor(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::L)){
        corpo.setFillColor(sf::Color::Magenta);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)){
        corpo.setFillColor(sf::Color::White);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::O)){
        corpo.setFillColor(sf::Color::Blue);
    }
}

void Player::atirar(std::vector<Projetil>& listaDeBalas) {
    sf::Vector2f pos = corpo.getPosition();

    if (relogioTiro.getElapsedTime().asSeconds() >= tempoRecarga) {
            
            bool atirou = false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
                listaDeBalas.push_back(Projetil((pos.x+raio), pos.y, 1));
                atirou = true;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
                listaDeBalas.push_back(Projetil((pos.x+raio), (pos.y+raio*2), 2));
                atirou = true;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
                listaDeBalas.push_back(Projetil(pos.x, (pos.y+raio), 3));
                atirou = true;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
                listaDeBalas.push_back(Projetil((pos.x+raio*2), (pos.y+raio), 4));
                atirou = true;
            }

            if (atirou) {
                 relogioTiro.restart(); // Zera o cronômetro para começar a contar de novo
            }



    
    }      
}
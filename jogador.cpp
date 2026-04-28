#include "jogador.h"
#include <SFML/Window/Keyboard.hpp>

// O Construtor faz o papel da função 'inicializar'
Player::Player() {
    corpo.setRadius(50.f);
    corpo.setFillColor(sf::Color::Blue);
    corpo.setPosition({400.f, 300.f});
    velocidade = 1.0f;
    raio = 50;
    tempoRecarga=0.5f;
}

sf::Vector2f Player::getPosiçao(){
    sf::Vector2f pos =  corpo.getPosition();
    return pos;
}



void Player::gerenciarMovimentacao(Mapa& map) {
    sf::Vector2f pos =  corpo.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        if(!map.Colisao({pos.x, pos.y - velocidade}))
            corpo.move({0.f, -velocidade});
        
        else    
            corpo.move({0.f,velocidade});
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
        if(!map.Colisao({pos.x, pos.y - velocidade+100}))
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
        if(!map.Colisao({pos.x+100, pos.y - velocidade}))
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
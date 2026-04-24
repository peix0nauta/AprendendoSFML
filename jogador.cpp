#include "jogador.h"

// O Construtor faz o papel da função 'inicializar'
Player::Player() {
    corpo.setRadius(50.f);
    corpo.setFillColor(sf::Color::Blue);
    corpo.setPosition({400.f, 300.f});
    velocidade = 1.0f;
}



void Player::gerenciarMovimentacao() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) corpo.move({0.f, -velocidade});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) corpo.move({0.f, velocidade});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) corpo.move({-velocidade, 0.f});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) corpo.move({velocidade, 0.f});
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


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        listaDeBalas.push_back(Projetil((pos.x+50), pos.y, 1));
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        listaDeBalas.push_back(Projetil((pos.x+50), (pos.y+102), 2));
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        listaDeBalas.push_back(Projetil(pos.x+2, (pos.y+50), 3));
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        listaDeBalas.push_back(Projetil((pos.x+102), (pos.y+50), 4));
    }
    
}
#include "tiro.h"

Projetil::Projetil(float x, float y,int dire){

    triangulo.setPointCount(3);
    triangulo.setPoint(0, sf::Vector2f(10.f, 0.f));
    triangulo.setPoint(1, sf::Vector2f(0.f, -5.f));  
    triangulo.setPoint(2, sf::Vector2f(0.f, 5.f));
    triangulo.setFillColor(sf::Color::Red);
    triangulo.setPosition({x,y});
    velo = 2.0;
    dir = dire;

}

Projetil::~Projetil(){


    
}
void Projetil::desenhar(sf::RenderWindow& window){
    window.draw(triangulo);

}

void Projetil::movebala() {
    if (dir == 1)      
        triangulo.move({0.f, -velo}); // Cima
    else if (dir == 2) 
        triangulo.move({0.f, velo});  // Baixo
    else if (dir == 3) 
        triangulo.move({-velo, 0.f}); // Esquerda
    else if (dir == 4) 
        triangulo.move({velo, 0.f});  // Direita
}

sf::Vector2f Projetil::getPosicao() const {
    return triangulo.getPosition(); 
}
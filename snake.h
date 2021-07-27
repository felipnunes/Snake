#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

const int slice_size = 20;

class snake {
    public:
    snake(sf::Window *window);
    int snake_inicial_lenght = 3;
    sf::RectangleShape snake_slice;
    std::vector<sf::RectangleShape> shape;
    void refresh();
    void addHead();
    void popHead();
    void drawSnake(sf::Window *window);
};

snake::snake(sf::Window *window) {
    this->snake_slice.setFillColor(sf::Color::Yellow);
    this->snake_slice.setScale(sf::Vector2f(slice_size,slice_size));
    for(int i = 0; i < snake_inicial_lenght; i++) {
        this->shape.push_back(snake_slice);
        this->shape[i].setPosition(sf::Vector2f(window->getSize().x/2 + slice_size * i,window->getSize().y/2));
    }
}

void snake::refresh() {
    //this->addHead();
    //this->popHead();
}

void snake::drawSnake(sf::Window *window) {
    sf::Window *ponteiro = window;
    for(int i = 0; i < this->shape.size(); i++) {
    }
}
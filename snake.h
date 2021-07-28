#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

const int slice_size = 20;

class snake {
    public:
    sf::RenderWindow *window_p;
    snake(sf::RenderWindow &window);
    int snake_inicial_lenght = 3;
    sf::RectangleShape snake_slice;
    std::vector<sf::RectangleShape> shape;
    void refresh();
    void addHead();
    void popHead();
    void drawSnake();
};

snake::snake(sf::RenderWindow &window) {
    this->window_p = &window;
    this->snake_slice.setFillColor(sf::Color::Yellow);
    this->snake_slice.setSize(sf::Vector2f(slice_size,slice_size));
    for(int i = 0; i < snake_inicial_lenght; i++) {
        this->shape.push_back(snake_slice);
        this->shape[i].setPosition(sf::Vector2f(window_p->getSize().x/2 + slice_size * i,window_p->getSize().y/2));
    }
}

void snake::refresh() {
    this->drawSnake();
    //this->addHead();
    //this->popHead();
}

void snake::drawSnake() {
    for(int i = 0; i < this->shape.size(); i++) {
        this->window_p->draw(shape[i]);
    }
}

void snake::addHead() {
    
}
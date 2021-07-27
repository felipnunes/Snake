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

};

snake::snake(sf::Window *window) {
    snake_slice.setFillColor(sf::Color::Yellow);
    snake_slice.setScale(sf::Vector2f(slice_size,slice_size));
    for(int i = 0; i < snake_inicial_lenght; i++) {
        shape.push_back(snake_slice);
    }
}

void snake::refresh() {
    this->addHead();
    this->popHead();
}
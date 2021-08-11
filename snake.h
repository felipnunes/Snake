#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

const int slice_size = 20;

class snake {
    public:
    int snake_inicial_lenght = 3;
    char actual_direction = 'D';
    int head_position_x;
    int head_position_y;
    sf::RenderWindow *window_p;
    sf::RectangleShape snake_slice;
    std::vector<sf::RectangleShape> shape;

    snake(sf::RenderWindow &window);
    void refresh();
    void addHead(char direction);
    void popTale();
    void drawSnake();
    void checkControls();
};

snake::snake(sf::RenderWindow &window) {
    this->window_p = &window;
    //define snake_slice
    this->snake_slice.setFillColor(sf::Color::Yellow);
    this->snake_slice.setSize(sf::Vector2f(slice_size,slice_size));
    //starts inicial snake
    for(int i = 0; i < snake_inicial_lenght; i++) {
        this->shape.push_back(snake_slice);
        this->shape[i].setPosition(sf::Vector2f(window_p->getSize().x/2 + slice_size * i,window_p->getSize().y/2));
    }
    //remember head's position
    this->head_position_x = this->shape.back().getPosition().x;
    this->head_position_y = this->shape.back().getPosition().y;
}

void snake::refresh() {
    this->checkControls();
    this->popTale();
    this->addHead(actual_direction);
    this->drawSnake();
}

void snake::drawSnake() {
    for (const auto &shape : this->shape) {
        this->window_p->draw(shape);
    }
}

void snake::checkControls() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->actual_direction = 'W';
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->actual_direction = 'A';
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->actual_direction = 'S';
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->actual_direction = 'D';
    }
}

void snake::addHead(char direction) {
    this->shape.push_back(snake_slice);
    if(direction == 'W') {
        this->shape.back().setPosition(sf::Vector2f(head_position_x,head_position_y - slice_size));
        head_position_y -= slice_size;
    }
    else if(direction == 'A') {
        this->shape.back().setPosition(sf::Vector2f(head_position_x - slice_size,head_position_y));
        head_position_x -= slice_size;
    }
    else if(direction == 'S') {
        this->shape.back().setPosition(sf::Vector2f(head_position_x,head_position_y + slice_size));
        head_position_y += slice_size;
    }
    else if(direction == 'D') {
        this->shape.back().setPosition(sf::Vector2f(head_position_x + slice_size,head_position_y));
        head_position_x += slice_size;
    }
}

void snake::popTale() {
    this->shape.erase(this->shape.begin());
}

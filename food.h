#include<SFML/Graphics.hpp>
#include<iostream>
#include<stdlib.h>
class food {
    public:
    bool ate;
    const int food_size = 20;
    sf::RectangleShape actual_food;
    sf::RenderWindow *window_pt;
    food(sf::RenderWindow &window);
    void refresh(int snake_x, int snake_y);
    void randomizer();
    void ate_check(int snake_x, int snake_y);
    

};

food::food(sf::RenderWindow &window) {
    ate = false;
    this->window_pt = &window;
    this->actual_food.setSize(sf::Vector2f(food_size,food_size));
    this->actual_food.setFillColor(sf::Color::Red);
    this->actual_food.setPosition(sf::Vector2f(food_size * (rand() % 50), food_size * (rand() % 50)));
}

void food::refresh(int snake_x, int snake_y) {
    ate_check(snake_x,snake_y);

    if(ate == true) {
        this->randomizer();
        this->ate = false;
    }
    
}

void food::randomizer() {
    this->actual_food.setPosition(sf::Vector2f(food_size * (rand() % 50), food_size * (rand() % 50)));
}

void food::ate_check(int snake_x, int snake_y) {
    if(this->actual_food.getPosition().x == snake_x && this->actual_food.getPosition().y == snake_y) {
        this->ate = true;
    }
    else {
        this->ate = false;
    }
}


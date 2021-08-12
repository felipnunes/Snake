#include<SFML/Graphics.hpp>
#include<iostream>
#include<stdlib.h>
class food {
    public:
    const int food_size = 20;
    sf::RectangleShape actual_food;
    sf::RenderWindow *window_pt;
    food(sf::RenderWindow &window);
    void randomizer();
    

};

food::food(sf::RenderWindow &window) {
    this->window_pt = &window;
    this->actual_food.setSize(sf::Vector2f(food_size,food_size));
    this->actual_food.setFillColor(sf::Color::Red);
    this->actual_food.setPosition(sf::Vector2f(food_size * (rand() % 50), food_size * (rand() % 50)));
}

void food::randomizer() {
    this->actual_food.setPosition(sf::Vector2f(food_size * (rand() % 50), food_size * (rand() % 50)));
}
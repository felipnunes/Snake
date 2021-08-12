  
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "snake.h"
#include "food.h"


int main() {
    int game_refresh_rate = 15;

    sf::RenderWindow window(sf::VideoMode(1000,1000), "Snake");
    window.setFramerateLimit(game_refresh_rate);
    snake *viper = new snake(window);
    food *fruit = new food(window);


    
    while(window.isOpen()) {

       


        sf::Event event;
        //event polling
        while(window.pollEvent(event)) {
            if(event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();

        viper->refresh(fruit->actual_food.getPosition().x, fruit->actual_food.getPosition().y); // Updating
        window.draw(fruit->actual_food);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            fruit->randomizer();
        }
        window.display(); // Rendering
    }

    return 0;
}

//g++ -c main.cpp && g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio && ./sfml-app
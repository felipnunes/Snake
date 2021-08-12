  
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "snake.h"
#include "food.h"


int main() {
    int game_refresh_rate = 10;

    sf::RenderWindow window(sf::VideoMode(1000,1000), "Snake");
    //window.setVerticalSyncEnabled(true);
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

        viper->refresh(); // Updating
        window.draw(fruit->actual_food);
        fruit->randomizer();
        window.display(); // Rendering
        //Sleep(50);
    }

    return 0;
}

//g++ -c main.cpp && g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio && ./sfml-app
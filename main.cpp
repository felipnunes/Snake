#include <SFML/Graphics.hpp>
#include <iostream>
#include "snake.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(1000,1000), "Snake");
    window.setVerticalSyncEnabled(true);
    snake *viper = new snake(window);
    
    
    while(window.isOpen()) {
        sf::Event event;

        //event polling
        while(window.pollEvent(event)) {
            if(event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed) {
                window.close();
            }
        }

        //Updating

        //Render
       // window.clear(); // clear the old frame

        //.......here you draw your game.......//
        viper->refresh();

        window.display(); // tell app that is done drawing

    }
    return 0;
}

//g++ -c main.cpp && g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio && sfml-app.exe

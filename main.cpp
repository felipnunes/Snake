  
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "snake.h"
#include <windows.h>

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
        window.clear();

        viper->refresh(); // Updating

        window.display(); // Rendering
        Sleep(50);
    }

    return 0;
}

//g++ -c main.cpp && g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio && ./sfml-app.exe
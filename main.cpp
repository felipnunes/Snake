#include <SFML/Graphics.hpp>
#include <iostream>
#include "snake.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(1000,1000), "Snake");
    window.setVerticalSyncEnabled(true);
    snake *viper = new snake(window);
    
    const unsigned int delay = 10;
    unsigned int tick = 0;
    
    while(window.isOpen()) {
        sf::Event event;

        //event polling
        while(window.pollEvent(event)) {
            if(event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        if (tick % delay != 0) {
            tick++;
            continue;
        } else {
            tick = 0;
        }
        
        viper->refresh(); // Updating

        window.display(); // Rendering

    }
    return 0;
}

//g++ -c main.cpp && g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio && sfml-app.exe

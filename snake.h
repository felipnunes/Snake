#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>

const int slice_size = 20;
const int frame_rate_increment = 2;
class snake {
    public:
    sf::Font font;
    sf::Text actual_pontuation_text;
    int points;
    sf::SoundBuffer bite_buffer;
    sf::Sound bite_sound;
    int snake_inicial_lenght = 8;
    char actual_direction = 'D';
    int head_position_x;
    int head_position_y;
    sf::RenderWindow *window_p;
    sf::RectangleShape snake_slice;
    std::vector<sf::RectangleShape> shape;

    snake(sf::RenderWindow &window);
    void refresh(float x, float y, sf::RenderWindow *window, int *actual_frame_rate);
    void addHead(char direction);
    void popTale();
    void drawSnake();
    void checkControls();
    void playSound();
    void frameRateAjust(sf::RenderWindow &window, int &actual_frame_rate);
    std::string turn_int_into_text();
    void checkColision(sf::RenderWindow &window);
};

snake::snake(sf::RenderWindow &window) {
    //inicializating actual_pontuation_text
    font.loadFromFile("MyHandwritingSucks.ttf");
    actual_pontuation_text.setString("0");
    actual_pontuation_text.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y /10));
    actual_pontuation_text.setFont(font);
    actual_pontuation_text.setFillColor(sf::Color::White);
    actual_pontuation_text.setScale(2,2);

    this->window_p = &window;
    //define inicial points
    points = 0;
    //define bite sound
    bite_buffer.loadFromFile("bite_sound.wav");
    bite_sound.setBuffer(bite_buffer);

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

void snake::refresh(float x, float y, sf::RenderWindow *window, int *actual_frame_rate) {
    this->checkControls();
    this->addHead(actual_direction);
    checkColision(*window);

    if(!(this->head_position_x == x && this->head_position_y == y)) {
       this->popTale();
    }
    else {
        playSound();
        this->points++;
        frameRateAjust(*window,*actual_frame_rate);
        actual_pontuation_text.setString(turn_int_into_text());
        
    }

    window->draw(this->actual_pontuation_text);
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

void snake::playSound() {
    bite_sound.play();
}

void snake::frameRateAjust(sf::RenderWindow &window, int &actual_frame_rate) {
    if(this->points % 5 == 0) {
        actual_frame_rate += frame_rate_increment;
        window.setFramerateLimit(actual_frame_rate);
    }
}

std::string snake::turn_int_into_text() {
    return std::to_string(this->points); 
}
void snake::checkColision(sf::RenderWindow &window) {

    // //check snake-snake colision
    // for(int i = 0; i < this->shape.size() - 1; i++) {
    //     if(this->shape.back().getPosition().x == this->shape[i].getPosition().x && this->shape.back().getPosition().x  == this->shape[i].getPosition().y) {
    //         //window.close();
    //     }
    //     else {

    //     }
    //     std::cout << this->head_position_x<< "----" << this->shape[i].getPosition().x << ":::::" << this->head_position_y<< "----" << this->shape[i].getPosition().y << std::endl;
    // }


    if(this->head_position_x >= window.getSize().x || this->head_position_x < 0 || this->head_position_y == window.getSize().y || this->head_position_y < 0) {
        window.close();
    }
}
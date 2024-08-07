#include <SFML/Graphics.hpp>
#include <iostream>
#include "globals.hpp"

Scene currentScene;
Direction currentDirection;

Snake snake;
Food food;

sf::Font font;
sf::Text text;

int score;

int main() {
  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake game");
  window.setFramerateLimit(10);

  currentScene = MAIN_SCENE;
  currentDirection = RIGHT;
  snake.reset();
  food.reset();
  score = 0;

  if (!font.loadFromFile("font/ComicMono.ttf")) {
    std::cerr << "Cannot load font. " << std::endl;
    return 1;
  }

  text.setFont(font);
  text.setCharacterSize(30);
  text.setFillColor(sf::Color::Black);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed: 
          window.close();
        break;
        case sf::Event::KeyPressed:
          switch (currentScene) {
            case MAIN_SCENE:
              switch (event.key.scancode) {
                case sf::Keyboard::Scan::Up:
                  if (currentDirection == DOWN) { break; }
                  currentDirection = UP;
                break;
                case sf::Keyboard::Scan::Down:
                  if (currentDirection == UP) { break; }
                  currentDirection = DOWN;
                break;
                case sf::Keyboard::Scan::Left:
                  if (currentDirection == RIGHT) { break; }
                  currentDirection = LEFT;
                break;
                case sf::Keyboard::Scan::Right:
                  if (currentDirection == LEFT) { break; }
                  currentDirection = RIGHT;
                break;
              }
            break;
            case DEATH_SCENE:
              switch (event.key.scancode) {
                case sf::Keyboard::Scan::Space:
                  snake.reset();
                  food.reset();
                  score = 0;
                  currentDirection = RIGHT;
                  currentScene = MAIN_SCENE;
                break;
              }
            break;
          }
          
        break;
      }
    }
    window.clear(sf::Color::White);
    switch (currentScene) {
      case MAIN_SCENE:
        mainScene(window);
      break;
      case DEATH_SCENE:
      break;
    }
    window.display();
  }
  return 0;
}
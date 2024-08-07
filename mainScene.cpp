#include <iostream>
#include "globals.hpp"

void mainScene(sf::RenderWindow &window) {
  snake.update();
  text.setPosition(sf::Vector2f(0, 0));
  text.setString("Score: " + std::to_string(score));
  snake.draw(window);
  food.draw(window);
  window.draw(text);
}
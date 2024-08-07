#include <random>
#include "globals.hpp"

void Food::reset() {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist(0, WINDOW_WIDTH_TILE_COUNT-1);
  x = dist(rng);
  y = dist(rng);
}

void Food::draw(sf::RenderWindow &window) {
  sf::RectangleShape f(sf::Vector2f(16, 16));
  f.setFillColor(sf::Color::Red);
  f.setPosition(sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE));
  window.draw(f);
}
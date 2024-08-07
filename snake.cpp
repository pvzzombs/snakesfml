#include <iostream>
#include "globals.hpp"

SnakeSegment::SnakeSegment(int x_, int y_) {
  x = x_;
  y = y_;
}

void Snake::reset() {
  body.clear();
  body.push_back(SnakeSegment(2, 0));
  body.push_back(SnakeSegment(1, 0));
  body.push_back(SnakeSegment(0, 0));
}

void Snake::update() {
  for (int i = body.size() - 1; i > 0; i--) {
    body.at(i) = body.at(i - 1);
  }
  switch (currentDirection) {
    case RIGHT:
      body.at(0).x += 1;
    break;
    case LEFT:
      body.at(0).x -= 1;
    break;
    case UP:
      body.at(0).y -= 1;
    break;
    case DOWN:
      body.at(0).y += 1;
    break;
  }

  // check for food collision
  if (body.at(0).x == food.x && body.at(0).y == food.y) {
    SnakeSegment h(body.at(0).x, body.at(0).y);
    switch (currentDirection) {
      case UP:
        h.y -= 1;
      break;
      case LEFT:
        h.x -= 1;
      break;
      case RIGHT:
        h.x += 1;
      break;
      case DOWN:
        h.y += 1;
      break;
    }
    body.insert(body.begin(), h);
    food.reset();
    ++score;
  }

  // check head if collides with borders
  SnakeSegment head = body.at(0);
  // if (head.x < 0 || head.x >= WINDOW_WIDTH_TILE_COUNT ||
  //     head.y < 0 || head.y >= WINDOW_HEIGHT_TILE_COUNT) {
  //   currentScene = DEATH_SCENE;
  //   return ;
  // }

  // teleport to other border side
  if (head.x < 0) {
    body.at(0).x = WINDOW_WIDTH_TILE_COUNT - 1;
  } else if (head.x > WINDOW_WIDTH_TILE_COUNT - 1) {
    body.at(0).x = 0;
  } else if (head.y < 0) {
    body.at(0).y = WINDOW_HEIGHT_TILE_COUNT - 1;
  } else if (head.y > WINDOW_HEIGHT_TILE_COUNT - 1) {
    body.at(0).y = 0;
  }

  // check head if collides with its body
  // std::cout << "(HEAD) " << head.x << ", " << head.y << std::endl;
  for (int i = 1; i < body.size(); i++) {
    if (head.x == body.at(i).x && head.y == body.at(i).y) {
      // std::cout << body.at(i).x << ", " << body.at(i).y << std::endl;
      currentScene = DEATH_SCENE;
      return;
    }
  }
}

void Snake::draw(sf::RenderWindow &window) {
  sf::RectangleShape rect(sf::Vector2f(TILE_SIZE, TILE_SIZE));
  rect.setFillColor(sf::Color::Green);
  rect.setOutlineColor(sf::Color::Black);
  for (int i = 0; i < body.size(); i++) {
    SnakeSegment segment = body.at(i);
    rect.setPosition(sf::Vector2f(segment.x * TILE_SIZE, segment.y * TILE_SIZE));
    window.draw(rect);
  }
}
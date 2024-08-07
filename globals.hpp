#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#define TILE_SIZE 16
#define WINDOW_WIDTH_TILE_COUNT 20
#define WINDOW_HEIGHT_TILE_COUNT 20
#define WINDOW_WIDTH TILE_SIZE*WINDOW_WIDTH_TILE_COUNT
#define WINDOW_HEIGHT TILE_SIZE*WINDOW_HEIGHT_TILE_COUNT

enum Scene {
  MAIN_SCENE,
  DEATH_SCENE
};

enum Direction {
  UP,
  DOWN,
  LEFT,
  RIGHT
};

struct SnakeSegment {
  int x, y;
  SnakeSegment(int x_, int y_);
};

class Snake {
  std::vector<SnakeSegment> body;
public:
  void reset();
  void update();
  void draw(sf::RenderWindow &window);
};

class Food {
public:
  int x, y;
  void reset();
  void draw(sf::RenderWindow &window);
};

void mainScene(sf::RenderWindow &window);
void deathScene(sf::RenderWindow &window);

extern Scene currentScene;
extern Direction currentDirection;

extern Snake snake;
extern Food food;

extern sf::Font font;
extern sf::Text text;

extern int score;
#pragma once

#include "Renderer.h"

#include <allegro5/allegro.h>

class Game {
private:
  ALLEGRO_TIMER *_timer;
  ALLEGRO_EVENT_QUEUE *_queue;

  Renderer *_renderer;

public:
  Game();
  ~Game();

  void mainLoop();
};

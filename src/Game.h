#pragma once

#include "Renderer.h"

#include <allegro5/allegro.h>

class Game {
private:
  ALLEGRO_DISPLAY* _display;
  ALLEGRO_FONT* _font;
  ALLEGRO_TIMER* _timer;
  ALLEGRO_EVENT_QUEUE* _queue;

public:
  Game();
  ~Game();

  ALLEGRO_FONT *get_font() const;

  void mainLoop();
};

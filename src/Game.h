#pragma once

#include <allegro5/allegro.h>

class Game
{
private:
  ALLEGRO_DISPLAY* _display;
  ALLEGRO_TIMER* _timer;
  ALLEGRO_EVENT_QUEUE* _queue;

public:
  Game();
  ~Game();

  void mainLoop();
  int retornaposmouse_x();
  int retornaposmouse_y();
};

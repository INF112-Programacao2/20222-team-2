#pragma once

#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"

#include "GameObject.h"

class Tabuleiro : public GameObject {
private:
public:
  Tabuleiro();
  ~Tabuleiro() {}

  virtual void onRender();
};

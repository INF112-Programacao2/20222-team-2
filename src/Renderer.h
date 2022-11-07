#pragma once

#include "Text.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

class Renderer {
private:
  ALLEGRO_DISPLAY *_display;
  ALLEGRO_FONT *_font;

public:
  Renderer();
  ~Renderer();

  ALLEGRO_DISPLAY *get_display() const;
  ALLEGRO_FONT *get_font() const;

  void clear();
  void draw(const Text& d);
  void commit();
};

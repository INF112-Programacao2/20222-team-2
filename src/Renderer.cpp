#include "Renderer.h"

#include <iostream>

Renderer::Renderer() {
  _display = al_create_display(640, 640);
  if (!_display) {
    std::cerr << "couldn't initialize display" << std::endl;
    exit(1);
  }

  _font = al_create_builtin_font();
  if (!_font) {
    printf("couldn't initialize font\n");
    exit(1);
  }
}

Renderer::~Renderer() {
  al_destroy_font(_font);
  al_destroy_display(_display);
}

ALLEGRO_DISPLAY *Renderer::get_display() const {
  return _display;
}

ALLEGRO_FONT *Renderer::get_font() const {
  return _font;
}

void Renderer::commit() { al_flip_display(); }

void Renderer::clear() { al_clear_to_color(al_map_rgb(0, 0, 0)); }

void Renderer::draw(const Text &text) {
  al_draw_text(_font, al_map_rgb(text.get_color().red, text.get_color().green, text.get_color().blue),
               text.get_pos().get_x(), text.get_pos().get_y(), 0, &text.get_text().c_str()[0]);
}

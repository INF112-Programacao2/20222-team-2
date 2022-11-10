#include "Text.h"

Text::Text(Position pos, RGBColor color, const std::string &text)
    : _pos(pos), _color(color), _text(text)
{
}

Position Text::get_pos() const {
  return _pos;
}

std::string Text::get_text() const {
  return _text;
}

RGBColor Text::get_color() const {
  return _color;
}

void Text::onRender(ALLEGRO_FONT* font) {
  al_draw_text(font, al_map_rgb(_color.red, _color.green, _color.blue),
               _pos.get_x(), _pos.get_y(), 0, &_text.c_str()[0]);
}

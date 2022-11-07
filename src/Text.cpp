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

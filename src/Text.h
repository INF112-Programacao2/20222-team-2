#pragma once

#include "Position.h"

#include <string>

struct RGBColor {
  unsigned char red;
  unsigned char green;
  unsigned char blue;
};

class Text {
private:
  Position _pos;
  RGBColor _color;
  std::string _text;

public:
  Text(Position pos, RGBColor color, const std::string &text);
  ~Text() {}

  Position get_pos() const;
  std::string get_text() const;
  RGBColor get_color() const;
};

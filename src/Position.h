#pragma once

class Position {
private:
  float _pos_x;
  float _pos_y;

public:
  Position(float pos_x, float pos_y);
  ~Position() {}

  float get_x();
  float get_y();
};

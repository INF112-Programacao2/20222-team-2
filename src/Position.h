#pragma once

class Position
{
private:
  float _pos_x;
  float _pos_y;

public:
  Position(float pos_x, float pos_y);
  ~Position() {}

  float get_x();
  float get_y();
  float set_x(float pos_x);
  float set_y(float pos_y);
  // Função para mover a peça
  void movepeca(float x, float y);
};

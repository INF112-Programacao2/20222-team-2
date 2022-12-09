#pragma once

#include <chrono>

#include "GameObject.h"

class Timer : public GameObject
{
private:
  std::chrono::time_point<std::chrono::system_clock> _startTime;

public:
  Timer();
  ~Timer() {}

  void update();
  long long int get_hours();
  long long int get_minutes();
  long long int get_seconds();

  virtual void onRender() override;
};
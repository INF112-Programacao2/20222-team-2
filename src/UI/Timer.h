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

  void reset();
  long long int get_hours() const;
  long long int get_minutes() const;
  long long int get_seconds() const;

  virtual void onRender() const override;
};
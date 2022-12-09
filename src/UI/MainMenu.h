#pragma once

#include "GameObject.h"

class MainMenu : public GameObject
{
private:
public:
  MainMenu();
  ~MainMenu() {}

  virtual void onRender() override;
};
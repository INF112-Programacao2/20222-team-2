#include "Game.h"

#include <iostream>

extern ALLEGRO_FONT* _font;

Game::Game() {
  if (!al_init()) {
    std::cerr << "couldn't initialize allegro" << std::endl;
    exit(1);
  }

  if (!al_install_keyboard()) {
    std::cerr << "couldn't initialize keyboard" << std::endl;
    exit(1);
  }

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

  _timer = al_create_timer(1.0 / 30.0);
  if (!_timer) {
    std::cerr << "couldn't initialize timer" << std::endl;
    exit(1);
  }

  _queue = al_create_event_queue();
  if (!_queue) {
    std::cerr << "couldn't initialize queue" << std::endl;
    exit(1);
  }

  al_register_event_source(_queue, al_get_keyboard_event_source());
  al_register_event_source(_queue, al_get_display_event_source(_display));
  al_register_event_source(_queue, al_get_timer_event_source(_timer));
}

Game::~Game() {
  al_destroy_timer(_timer);
  al_destroy_event_queue(_queue);
  al_destroy_font(_font);
  al_destroy_display(_display);
}

void Game::mainLoop() {
  bool done = false;
  bool redraw = true;
  ALLEGRO_EVENT event;

  Text text({ 64, 64 }, { 255, 0, 0 }, "Hello World");
  Tabuleiro t;

  al_start_timer(_timer);
  while (1) {
    al_wait_for_event(_queue, &event);

    switch (event.type) {
    case ALLEGRO_EVENT_TIMER:
      // game logic goes here.
      redraw = true;
      break;

    // case ALLEGRO_EVENT_KEY_DOWN:
    case ALLEGRO_EVENT_DISPLAY_CLOSE:
      done = true;
      break;
    }

    if (done) {
      break;
    }

    if (redraw && al_is_event_queue_empty(_queue)) {
      al_clear_to_color(al_map_rgb(0, 0, 0)); 

      t.onRender();
      text.onRender();

      al_flip_display(); 

      redraw = false;
    }
  }

}

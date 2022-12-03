#include "Game.h"

#include <allegro5/allegro_image.h>

#include <imgui.h>
#include <imgui_impl_allegro5.h>

#include <iostream>

#include "Text.h"
#include "Tabuleiro.h"
#include "Rei.h"

#include "constants.h"
#include "globals.h"
#include "errorHandling.h"


Game::Game() {
  // inicializa allegro e seus sistemas
  EC_CALL(al_init());
  EC_CALL(al_install_keyboard());
  EC_CALL(al_install_mouse()); //Instalação do mouse
  EC_CALL(_display = al_create_display(SCREEN_W, SCREEN_H));
  EC_CALL(_font = al_create_builtin_font());
  EC_CALL(al_init_image_addon());
  EC_CALL(al_init_primitives_addon());

  // carregar imagens das pecas
  // pretas
  EC_CALL(_kingBlackBmp = al_load_bitmap("./assets/Chess_kdt45.png"));
  EC_CALL(_queenBlackBmp = al_load_bitmap("./assets/Chess_qdt45.png"));
  EC_CALL(_bishopBlackBmp = al_load_bitmap("./assets/Chess_bdt45.png"));
  EC_CALL(_knightBlackBmp = al_load_bitmap("./assets/Chess_ndt45.png"));
  EC_CALL(_rookBlackBmp = al_load_bitmap("./assets/Chess_rdt45.png"));
  EC_CALL(_pawnBlackBmp = al_load_bitmap("./assets/Chess_pdt45.png"));
  // brancas
  EC_CALL(_kingWhiteBmp = al_load_bitmap("./assets/Chess_klt45.png"));
  EC_CALL(_queenWhiteBmp = al_load_bitmap("./assets/Chess_qlt45.png"));
  EC_CALL(_bishopWhiteBmp = al_load_bitmap("./assets/Chess_blt45.png"));
  EC_CALL(_knightWhiteBmp = al_load_bitmap("./assets/Chess_nlt45.png"));
  EC_CALL(_rookWhiteBmp = al_load_bitmap("./assets/Chess_rlt45.png"));
  EC_CALL(_pawnWhiteBmp = al_load_bitmap("./assets/Chess_plt45.png"));

  // inicializa o timer para rodar o jogo a 30 fps
  EC_CALL(_timer = al_create_timer(1.0 / 30.0));

  // cria fila de eventos para usar com a API da allegro
  EC_CALL(_queue = al_create_event_queue());
  al_register_event_source(_queue, al_get_keyboard_event_source());
  al_register_event_source(_queue , al_get_mouse_event_source());
  al_register_event_source(_queue, al_get_display_event_source(_display));
  al_register_event_source(_queue , al_get_mouse_event_source()); //New evento para o mouse
  al_register_event_source(_queue, al_get_timer_event_source(_timer));

  // define o alvo padrão para renderizar na tela
  al_set_target_bitmap(al_get_backbuffer(_display));

  // Inicializar contexto da Dear ImGui
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;
  ImGui::StyleColorsLight();
  ImGui_ImplAllegro5_Init(_display);
}

Game::~Game() {
  // Limpa o contexto da Dear ImGui
    ImGui_ImplAllegro5_Shutdown();
    ImGui::DestroyContext();

  // desaloca todas as imagens das peças
  // pretas
  al_destroy_bitmap(_kingBlackBmp);
  al_destroy_bitmap(_queenBlackBmp);
  al_destroy_bitmap(_bishopBlackBmp);
  al_destroy_bitmap(_knightBlackBmp);
  al_destroy_bitmap(_rookBlackBmp);
  al_destroy_bitmap(_pawnBlackBmp);
  // brancas
  al_destroy_bitmap(_kingWhiteBmp);
  al_destroy_bitmap(_queenWhiteBmp);
  al_destroy_bitmap(_bishopWhiteBmp);
  al_destroy_bitmap(_knightWhiteBmp);
  al_destroy_bitmap(_rookWhiteBmp);
  al_destroy_bitmap(_pawnWhiteBmp);

  // desinicializa e destrói os sistemas da allegro
  al_shutdown_image_addon();
  al_shutdown_font_addon();
  al_shutdown_primitives_addon();
  al_destroy_timer(_timer);
  al_destroy_event_queue(_queue);
  al_destroy_font(_font);
  al_destroy_display(_display);
  al_uninstall_mouse();
  al_uninstall_system();
}

void Game::mainLoop() {
  // Variáveis para ImGui
  bool show_demo_window = true;
  bool show_another_window = false;

  bool running = true;
  bool redraw = true;
  ALLEGRO_EVENT event;
  int posmouse_x; //Posição inicial x do mouse com botão esquerdo pressionado
  int posmouse_y; //Posição inicial y do mouse com botão esquerdo pressionado
  int posmouse_x2; //Posição inicial x do mouse com botão direito pressionado
  int posmouse_y2; //Posição inicial y do mouse com botão direito pressionado

  // Text text({ 64, 64 }, { 255, 0, 0 }, "Hello World");
  // Rei r(Cor::BRANCO, { 1, 1 }, _kingWhiteBmp);
  Tabuleiro t;
  
  
  t.inicializarJogo();

  al_start_timer(_timer);
  while (running) {
    al_wait_for_event(_queue, &event);

    ImGui_ImplAllegro5_ProcessEvent(&event);

    switch (event.type) {
    case ALLEGRO_EVENT_TIMER:
      // game logic goes here.
      redraw = true;
      break;

    case ALLEGRO_EVENT_KEY_DOWN:
      if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
        running = false;
      }
      break;
      
    case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
    case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
      std::cout << "Mouse button " << event.mouse.button << " at (" << event.mouse.x << ", " << event.mouse.y << ")" << std::endl;
      break;

    case ALLEGRO_EVENT_DISPLAY_CLOSE:
      running = false;
      break;
    }

    if (redraw && al_is_event_queue_empty(_queue)) {
      al_clear_to_color(al_map_rgb(0, 0, 0)); 

      // Start the Dear ImGui frame
      ImGui_ImplAllegro5_NewFrame();
      ImGui::NewFrame();

      // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
      if (show_demo_window)
          ImGui::ShowDemoWindow(&show_demo_window);

      // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
      {
          static float f = 0.0f;
          static int counter = 0;

          ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

          ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
          ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
          ImGui::Checkbox("Another Window", &show_another_window);

          ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f

          if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
              counter++;
          ImGui::SameLine();
          ImGui::Text("counter = %d", counter);

          ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
          ImGui::End();
      }

      // 3. Show another simple window.
      if (show_another_window)
      {
          ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
          ImGui::Text("Hello from another window!");
          if (ImGui::Button("Close Me"))
              show_another_window = false;
          ImGui::End();
      }

      t.onRender();

      // Atualiza tela (render)
      ImGui::Render();
      ImGui_ImplAllegro5_RenderDrawData(ImGui::GetDrawData());
      al_flip_display(); 

      redraw = false;
    }

//Função para adicionar a funcionalidade do mouse dentro do display e descobrir sua posição
  switch (event.type) {
    case ALLEGRO_EVENT_TIMER:
      // game logic goes here.
      redraw = true;
      break;

    case ALLEGRO_EVENT_KEY_DOWN:
      if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
        
      }
      break;
    
    case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
    case ALLEGRO_EVENT_MOUSE_BUTTON_UP:

    if(event.mouse.button & 1){
      posmouse_x = event.mouse.x/80;
      posmouse_y = event.mouse.y/80;
      std::cout << "Posição X: " << posmouse_x << " Posição Y: " << posmouse_y << std::endl;
    }
    else if(event.mouse.button & 2){
      posmouse_x2 = event.mouse.x/80;
      posmouse_y2 = event.mouse.y/80;
      std::cout << "Posição X: " << posmouse_x2 << " Posição Y: " << posmouse_y2 << std::endl;
    }
    t.moverPeca(posmouse_x, posmouse_y, posmouse_x2, posmouse_y2);
     
      std::cout << "Mouse button " << event.mouse.button << " at (" << event.mouse.x/80 << ", " << event.mouse.y/80 << ")" << std::endl;
      break;
         
    case ALLEGRO_EVENT_DISPLAY_CLOSE:
      break;
    }
    }
  }
  



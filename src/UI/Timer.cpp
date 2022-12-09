#include "Timer.h"

#include <imgui.h>

#include "constants.h"

Timer::Timer()
  : _startTime(std::chrono::system_clock::now())
{
}

long long int
Timer::get_hours() const
{
  return std::chrono::duration_cast<std::chrono::hours>(std::chrono::system_clock::now() -
                                                        _startTime)
    .count();
}

long long int
Timer::get_minutes() const
{
  return std::chrono::duration_cast<std::chrono::minutes>(std::chrono::system_clock::now() -
                                                          _startTime)
    .count();
}

long long int
Timer::get_seconds() const
{
  return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() -
                                                          _startTime)
.count();
}

void
Timer::onRender() const
{
  const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
  ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x, main_viewport->WorkPos.y));
  ImGui::SetNextWindowSize(ImVec2(SCREEN_W, OFFSET_Y));

  // TODO: create global window flags for static windows, and maybe other window types
  ImGuiWindowFlags window_flags = 0;
  window_flags |= ImGuiWindowFlags_NoTitleBar;
  window_flags |= ImGuiWindowFlags_NoScrollbar;
  window_flags |= ImGuiWindowFlags_NoMove;
  window_flags |= ImGuiWindowFlags_NoResize;
  window_flags |= ImGuiWindowFlags_NoCollapse;
  window_flags |= ImGuiWindowFlags_NoNav;
  ImGui::Begin("status", nullptr, window_flags);

  ImGui::Text("Tempo: ");
  ImGui::SameLine();
  ImGui::Text("%02lld:%02lld:%02lld", get_hours(), get_minutes(), (get_seconds() % 60));

  ImGui::End();
}

void Timer::reset()
{
  _startTime = std::chrono::system_clock::now();
}
#pragma once
#include <cassert>
#include <windows.h>

#pragma comment(lib, "user32.lib")

#define ESC_KEY   (0x1B) 

constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;

class WinApp {
public:
   static int Run(HINSTANCE hIns);

private:
   static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
   static HWND hWnd;
};


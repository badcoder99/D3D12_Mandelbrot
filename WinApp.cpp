#include "WinApp.h"

HWND WinApp::hWnd = NULL;

int WinApp::Run(HINSTANCE hIns) {
   WNDCLASSEX wnd {
      sizeof(WNDCLASSEX),
      CS_HREDRAW | CS_VREDRAW,
      WndProc,
      0,
      0,
      hIns,
      NULL,
      LoadCursor(NULL, IDC_ARROW),
      NULL,
      NULL,
      "WindowClass",
      NULL
   };
   if (!RegisterClassEx(&wnd)) {
      assert(false);
   }
   
   RECT rect { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
   AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);
  
   hWnd = CreateWindow(
      wnd.lpszClassName,
      "D3D12 Mandelbrot",
      WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT,
      CW_USEDEFAULT,
      rect.right - rect.left,
      rect.bottom - rect.top,
      NULL,
      NULL,
      hIns,
      NULL
   );
   ShowWindow(hWnd, SW_SHOW);

   MSG msg;
   while (GetMessage(&msg, NULL, 0, 0)) {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
   }
   return msg.wParam;
}

LRESULT CALLBACK WinApp::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
   switch(msg) {
   case WM_CHAR:
      switch (wParam) {
      case ESC_KEY:
         PostQuitMessage(0);
         break;
      }
      break;
   
   case WM_DESTROY:
      PostQuitMessage(0);
      break;

   default: 
      return DefWindowProc(hWnd, msg, wParam, lParam); 
   }

   return 0;
}


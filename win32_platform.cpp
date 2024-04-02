#include <windows.h>

bool running = true;

LRESULT window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  LRESULT result = 0;
  switch (uMsg)
  {
    case WM_CLOSE:
    case WM_DESTROY:
    {
      running = false;
    }
    break;
    
    default:
    {
      result = DefWindowProc(hwnd, uMsg, wParam, lParam);
    }    
  }
  return result;    
}  

int WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
// Create Window class
  WNDCLASS window_class = {};
  window_class.style = CS_HREDRAW | CS_VREDRAW;
  window_class.lpszClassName = "Pong Window Class";
  window_class.lpfnWndProc = window_callback;

   // Register Window class
  RegisterClass(&window_class);

  HWND window = CreateWindow(window_class.lpszClassName, "Pong", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, 0, 0, hInst, 0);

  while (running)
  {
    // Input
    MSG message;
    while (PeekMessage(&message, window, 0, 0, PM_REMOVE))
    {
      TranslateMessage(&message);
      DispatchMessage(&message);
    }
    

    // Simulate

    // Render
  }

  return 0;
}
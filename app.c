#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#define sleep(n) Sleep(1000 * n)
#else
#include <unistd.h>
#endif

int main() {
#ifdef _WIN32
  HWND hwnd;
  WNDCLASSEX wc;
  MSG msg;

  // Register the window class
  ZeroMemory(&wc, sizeof(WNDCLASSEX));
  wc.cbSize = sizeof(WNDCLASSEX);
  wc.lpfnWndProc = DefWindowProc;
  wc.hInstance = GetModuleHandle(NULL);
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
  wc.lpszClassName = "MyClass";
  RegisterClassEx(&wc);

  // Create the window
  hwnd = CreateWindowEx(0, "MyClass", "My Window",WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,800, 600, NULL, NULL, GetModuleHandle(NULL), NULL);
  ShowWindow(hwnd, SW_SHOWDEFAULT);
  UpdateWindow(hwnd);

  // Message loop
  while (GetMessage(&msg, NULL, 0, 0) > 0) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
#else
  // Unix implementation using Xlib
  Display *dpy;
  Window w;
  XEvent e;

  dpy = XOpenDisplay(NULL);
  if (dpy == NULL) {
    fprintf(stderr, "Cannot open display\n");
    exit(1);
  }

  w = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy), 0, 0,
                          800, 600, 0, 0, WhitePixel(dpy, 0));
  XMapWindow(dpy, w);
  XFlush(dpy);

  while (1) {
    XNextEvent(dpy, &e);
    if (e.type == KeyPress)
      break;
  }

  XCloseDisplay(dpy);
#endif

  return 0;
}
#ifndef _FUNMAIN_H_
#define _FUNMAIN_H_

ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);

void GetWindowDimension(int& ,int&);
void Free();

  int APIENTRY FunMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow);

#endif
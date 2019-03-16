#include <Windows.h>

#include "../res/resource.h"

#include "WndProc.hpp"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR commandLine, int nCmdShow)
{
	auto hMainWnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_MAIN_WINDOW), NULL, WndProc);

	ShowWindow(hMainWnd, nCmdShow);	
	UpdateWindow(hMainWnd);


	MSG message;

	while (GetMessage(&message, nullptr, NULL, NULL))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	return 0;
}

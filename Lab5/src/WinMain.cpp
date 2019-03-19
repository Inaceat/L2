#include <Windows.h>

#include "../res/resource.h"

#include "MainWindowProcedure.hpp"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR commandLine, int nCmdShow)
{
	auto hMainWindow = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_MAIN_WINDOW), NULL, MainWindowProcedure);

	ShowWindow(hMainWindow, nCmdShow);
	UpdateWindow(hMainWindow);


	MSG message;

	while (GetMessage(&message, nullptr, NULL, NULL))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	return 0;
}

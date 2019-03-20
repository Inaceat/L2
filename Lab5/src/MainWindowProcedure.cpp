#include "MainWindowProcedure.hpp"


BOOL GetClientSize(HWND hWnd, int& width, int& height)
{
	RECT rectangle;

	BOOL result = GetClientRect(hWnd, &rectangle);

	if (result == TRUE)
	{
		width = rectangle.right - rectangle.left;
		height = rectangle.bottom - rectangle.top;
	}

	return result;
}


void DrawAllTheShit(HWND* hWnd, HDC* dc)
{
	//Get drawing area size
	int windowWidth;
	int windowHeight;

	GetClientSize(*hWnd, windowWidth, windowHeight);

	//Fill it with white
	RECT rect = { 0, 0, windowWidth + 1, windowHeight + 1 };
	FillRect(*dc, &rect, (HBRUSH)(COLOR_WINDOW + 1));
	

	//Draw things
	//Vase

	//POINT vasePoints[] = {{10,100}, {100, 100}, {100, 10}, {10, 10}};
	//Polygon(*dc, vasePoints, 4);
}




INT_PTR CALLBACK MainWindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int windowWidth;
	static int windowHeight;

	static HDC windowDC;
	static HDC bufferDC;

	
	switch (message)
	{
	case WM_INITDIALOG:
		//Get window size
		GetClientSize(hWnd, windowWidth, windowHeight);

		//Create memory DC for drawing
		windowDC = GetDC(hWnd);
		bufferDC = CreateCompatibleDC(windowDC);
		
		//Create bitmap and insert to buffer DC
		DeleteObject(SelectObject(bufferDC, CreateCompatibleBitmap(windowDC, windowWidth, windowHeight)));

		DrawAllTheShit(&hWnd, &bufferDC);

		break;


	case WM_PAINT:
		//Paste from buffer DC to screen
		windowDC = GetDC(hWnd);

		BitBlt(windowDC, 0, 0, windowWidth, windowHeight, bufferDC, 0, 0, SRCCOPY);

		ReleaseDC(hWnd, windowDC);

		break;


	case WM_CLOSE:
		PostQuitMessage(42);
		break;


	default:
		return FALSE;
	}

	return TRUE;
}

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


INT_PTR CALLBACK MainWindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int windowWidth;
	static int windowHeight;

	static HDC windowDC;
	static HDC bufferDC;


	switch (message)
	{
		case WM_CREATE:
			//Get window size
			GetClientSize(hWnd, windowWidth, windowHeight);

			//Create memory DC for drawing
			windowDC = GetDC(hWnd);
			
			bufferDC = CreateCompatibleDC(windowDC);

			//Create bitmap and insert to buffer DC
			DeleteObject(SelectObject(bufferDC, CreateCompatibleBitmap(windowDC, windowWidth, windowHeight)));

			break;


		case WM_PAINT:

			windowDC = GetDC(hWnd);
			BitBlt(windowDC	, 0, 0, windowWidth, windowHeight, bufferDC, 0, 0, SRCCOPY);

			break;


		case WM_CLOSE:
			PostQuitMessage(42);
			break;


		default:
			return FALSE;
	}

	return TRUE;
}

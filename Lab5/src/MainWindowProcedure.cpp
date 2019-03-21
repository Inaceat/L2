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


void DrawPainting(HWND* hWnd, HDC* dc)
{
	//Get drawing area size
	int windowWidth;
	int windowHeight;

	GetClientSize(*hWnd, windowWidth, windowHeight);

	//Fill it with white
	RECT rect = { 0, 0, windowWidth + 1, windowHeight + 1 };
	FillRect(*dc, &rect, (HBRUSH)(COLOR_WINDOW + 1));
	

	//Draw things
	//Pens
	auto solidGreen3pxPen = CreatePen(PS_SOLID, 3, RGB(0, 255, 0));
	auto dashDotDotRed1pxPen = CreatePen(PS_DASHDOTDOT, 1, RGB(255, 0, 0));
	auto solidDarkOrchid5pxPen = CreatePen(PS_DOT, 5, RGB(172, 34, 203));

	//Brushes
	auto hatchBdiagonalBlueBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(0, 0, 255));
	auto solidPinkBrush = CreateSolidBrush(RGB(255, 192, 203));
	auto hatchDiagcrossBrownBrush = CreateHatchBrush(HS_DIAGCROSS, RGB(163, 139, 105));

	//Vase
	auto oldPen = SelectObject(*dc, solidGreen3pxPen);
	auto oldBrush = SelectObject(*dc, hatchBdiagonalBlueBrush);

	POINT vasePoints[] = {{140, 420}, {300, 420}, {340, 330}, {280, 285}, {160, 285}, {100, 330}};
	Polygon(*dc, vasePoints, 6);
	
	
	//Left flower
	SelectObject(*dc, dashDotDotRed1pxPen);
	SelectObject(*dc, solidPinkBrush);

	MoveToEx(*dc, 180, 285, nullptr);
	LineTo(*dc, 160, 180);


	Rectangle(*dc, 120, 120, 200, 180);
	
	Rectangle(*dc, 40, 75, 140, 135);
	Rectangle(*dc, 60, 150, 140, 240);
	Rectangle(*dc, 180, 75, 260, 150);
	Rectangle(*dc, 160, 165, 260, 210);


	//Right flower
	SelectObject(*dc, solidDarkOrchid5pxPen);
	SelectObject(*dc, hatchDiagcrossBrownBrush);

	MoveToEx(*dc, 240, 285, nullptr);
	LineTo(*dc, 440, 195);

	Ellipse(*dc, 360, 165, 520, 225);

	Ellipse(*dc, 340, 120, 420, 195);
	Ellipse(*dc, 460, 135, 600, 210);
	Ellipse(*dc, 380, 195, 420, 255);


	//Signature
	char text[] = "Supa artest, supa peinting!!1!";
	TextOut(*dc, 500, 450, text, sizeof(text));

	//Reset pen and brush
	SelectObject(*dc, oldPen);
	SelectObject(*dc, oldBrush);

	DeleteObject(solidGreen3pxPen);
	DeleteObject(dashDotDotRed1pxPen);
	DeleteObject(solidDarkOrchid5pxPen);

	DeleteObject(hatchBdiagonalBlueBrush);
	DeleteObject(solidPinkBrush);
	DeleteObject(hatchDiagcrossBrownBrush);
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

		DrawPainting(&hWnd, &bufferDC);

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

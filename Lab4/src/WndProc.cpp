#include "WndProc.hpp"
#include "../res/resource.h"

#include "ComplexNumber.hpp"

#include <sstream>
#include <WinUser.h>


class DialogEditBox
{
public:
	DialogEditBox(HWND parentWindowHandle, int editBoxResourceID)
	{
		_handle = GetDlgItem(parentWindowHandle, editBoxResourceID);
	}

	std::string GetText() const
	{
		int textLength = GetWindowTextLength(_handle) + 1;


		LPSTR text = new char[textLength];

		GetWindowText(_handle, text, textLength);

		std::string result(text, textLength);


		delete[] text;

		return result;
	}

	void SetText(std::string text)
	{
		SetWindowText(_handle, text.c_str());
	}

private:
	HWND _handle;
};




INT_PTR CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_COMMAND:
		
			if (LOWORD(wParam) == IDC_BUTTON_MULTIPLY || LOWORD(wParam) == IDC_BUTTON_DIVIDE)
			{
				DialogEditBox firstReEditBox(hWnd, IDC_EDIT_FIRST_RE);
				DialogEditBox firstImEditBox(hWnd, IDC_EDIT_FIRST_IM);

				DialogEditBox secondReEditBox(hWnd, IDC_EDIT_SECOND_RE);
				DialogEditBox secondImEditBox(hWnd, IDC_EDIT_SECOND_IM);

				DialogEditBox resultReEditBox(hWnd, IDC_EDIT_RESULT_RE);
				DialogEditBox resultImEditBox(hWnd, IDC_EDIT_RESULT_IM);


				ComplexNumber firstNumber(firstReEditBox.GetText(), firstImEditBox.GetText());
				ComplexNumber secondNumber(secondReEditBox.GetText(), secondImEditBox.GetText());

				ComplexNumber resultNumber;

				if (LOWORD(wParam) == IDC_BUTTON_MULTIPLY)
					resultNumber = firstNumber * secondNumber;
				else
					resultNumber = firstNumber / secondNumber;

				resultReEditBox.SetText(resultNumber.RealToString());
				resultImEditBox.SetText(resultNumber.ImaginaryToString());
			}

			break; 
		

		case WM_CLOSE:
			PostQuitMessage(42);
			break;


		default:
			return FALSE;
	}

	return TRUE;
}

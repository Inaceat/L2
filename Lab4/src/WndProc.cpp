#include "WndProc.hpp"
#include "../res/resource.h"

#include <iosfwd>
#include <sstream>


int ParseInt(char* str)
{
	std::stringstream stream;

	stream << str;


	int result;

	stream >> result;

	return result;
}

std::string ToString(int i)
{
	std::stringstream stream;

	stream << i;


	std::string result;

	stream >> result;

	return result;
}



INT_PTR CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{



		case WM_COMMAND:
		
			if (LOWORD(wParam) == IDC_BUTTON_MULTIPLY || LOWORD(wParam) == IDC_BUTTON_DIVIDE)
			{
				int firstReLength = GetWindowTextLength(GetDlgItem(hWnd, IDC_EDIT_FIRST_RE));
				int firstImLength = GetWindowTextLength(GetDlgItem(hWnd, IDC_EDIT_FIRST_IM));

				int secondReLength = GetWindowTextLength(GetDlgItem(hWnd, IDC_EDIT_SECOND_RE));
				int secondImLength = GetWindowTextLength(GetDlgItem(hWnd, IDC_EDIT_SECOND_IM));


				LPSTR firstReString = new char[firstReLength + 1];
				firstReString[firstReLength] = '\0';
				
				LPSTR firstImString = new char[firstImLength + 1];
				firstImString[firstImLength] = '\0';


				LPSTR secondReString = new char[secondReLength + 1];
				secondReString[secondReLength] = '\0';

				LPSTR secondImString = new char[secondImLength + 1];
				secondImString[secondImLength] = '\0';


				GetWindowText(GetDlgItem(hWnd, IDC_EDIT_FIRST_RE), firstReString, firstReLength);
				GetWindowText(GetDlgItem(hWnd, IDC_EDIT_FIRST_IM), firstImString, firstImLength);

				GetWindowText(GetDlgItem(hWnd, IDC_EDIT_SECOND_RE), secondReString, secondReLength);
				GetWindowText(GetDlgItem(hWnd, IDC_EDIT_SECOND_IM), secondImString, secondImLength);



				int firstRe = ParseInt(firstReString);
				int firstIm = ParseInt(firstImString);

				int secondRe = ParseInt(secondReString);
				int secondIm = ParseInt(secondReString);



				int resultRe = 0;
				int resultIm = 0;

				if (LOWORD(wParam) == IDC_BUTTON_MULTIPLY)
				{
					resultRe = firstRe * secondRe - firstIm * secondIm;
					resultIm = firstIm * secondRe + firstRe * secondIm;
				}



				SetWindowText(GetDlgItem(hWnd, IDC_EDIT_RESULT_RE), ToString(resultRe).c_str());
				SetWindowText(GetDlgItem(hWnd, IDC_EDIT_RESULT_IM), ToString(resultIm).c_str());

				delete[] firstReString;
				delete[] firstImString;

				delete[] secondReString;
				delete[] secondImString;
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

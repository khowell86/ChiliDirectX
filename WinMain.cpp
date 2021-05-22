///GPL Source code rules need to be followed -- https://wiki.planetchili.net/ --  https://github.com/planetchili/hw3d

#include "WindowDotHFix.h"
//#include "GameWindow.h"
#include "App.h"
#include <sstream>
//#include "WindowsMessageMap.h"
//#include <SimpleMath.h>

/*
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static WindowsMessageMap mm;
	OutputDebugString(mm(msg, lParam, wParam).c_str());

	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(69);
		break;
	case WM_KEYDOWN:
		if (wParam == 'F')
		{
			SetWindowText(hWnd, "You Pressed F");
		}
		break;
	case WM_KEYUP:
		if (wParam == 'F')
		{
			SetWindowText(hWnd, "The Window");
		}
		break;
	case WM_CHAR:
		static string title;
		title.push_back((char)wParam);
		SetWindowText(hWnd, title.c_str());
		break;
	case WM_LBUTTONDOWN:
		POINTS pt = MAKEPOINTS(lParam);
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
*/

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	/*
	const auto pClassName = "Butts";

	//register window class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;

	RegisterClassEx( &wc);

	//Create Window instance

	HWND hWnd = CreateWindowEx(
		0,
		pClassName,
		"The Window",	//The Name In The Title Bar
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU | WS_MAXIMIZE,  //Add More Styles For Functionality 
		200, 200,		//Start Location
		640, 480,		//Window Size
		nullptr, nullptr, hInstance, nullptr);

	// Show the window
	ShowWindow(hWnd, SW_SHOW);
	*/
	try
	{
		return App{}.Go();
	}
	catch (const ExceptionType& e)
	{
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e)
	{
		MessageBox(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, "No Details Available", "Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}

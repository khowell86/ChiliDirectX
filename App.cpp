#include "App.h"
#include <sstream>
#include <iomanip>

App::App()
	:
	wnd(800, 600, "The Donkey Fart Box")
{

}

int App::Go()
{
	while (true)
	{
		//Process All Pending Messages, But To Not Block
		if (const auto ecode = Window::ProcessMessages())
		{
			//If Return Optional Has Value, Means
			return *ecode;
		}

		DoFrame();
	}

	/*
	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		//TranslateMessage will post auxillary WM_CHAR messages from key msgs
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		DoFrame();
	}

	//Check If GetMessage Call Itself Borked
	if (gResult == -1)
	{
		throw CHWND_LAST_EXCEPT();
	}

	// wParam Here Is The Value Passed To PostQuitMessage
	return msg.wParam;

	/*
	Window wnd(800, 450, "Donkey Fart Box");

	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		while (!wnd.mouse.IsEmpty())
		{
			const auto e = wnd.mouse.Read();
			switch (e.GetType())
			{
			case Mouse::Event::Type::Leave:
				wnd.SetTitle("Cursor Left Screen!");
				break;
			case Mouse::Event::Type::Enter:
				wnd.SetTitle("Phew.  It's Back.");
				break;
			case Mouse::Event::Type::Move:
			{
				ostringstream oss;
				oss << "Mouse Pointer Moved To (" << e.GetPosX() << ", " << e.GetPosY() << ")";
				wnd.SetTitle(oss.str());
			}
			break;
			case Mouse::Event::Type::LPress:
				wnd.SetTitle("Click");
				break;
			case Mouse::Event::Type::MPress:
				wnd.SetTitle("Clack");
				break;
			case Mouse::Event::Type::RPress:
				wnd.SetTitle("Clunk");
				break;
			case Mouse::Event::Type::WheelUp:
			{
				int i = 0;
				ostringstream oss;
				oss << "Scrolled Up";
				wnd.SetTitle(oss.str());
			}
			break;
			case Mouse::Event::Type::WheelDown:
			{
				ostringstream oss;
				oss << "Scrolled Down";
				wnd.SetTitle(oss.str());
			}
			break;


			}
		}

		if (wnd.kbd.KeyIsPressed(VK_SPACE))
		{
			MessageBox(nullptr, "Something Happened!!", "Space Key Was Pressed", MB_OK | MB_ICONEXCLAMATION);
		}
		else if (wnd.kbd.KeyIsPressed(VK_MENU))
		{
			MessageBox(nullptr, "Something Happened!!", "Alt Key Was Pressed", MB_OK | MB_ICONEXCLAMATION);
		}

	}

	if (gResult == -1)
	{
		return -1;
	}
	else
	{
		return msg.wParam;
	}*/
}

void App::DoFrame()
{
	const float t = tmr.Peek();
	std::ostringstream oss;
	oss << "Time Elapsed: " << std::setprecision(1) << std::fixed << t << "s";
	wnd.SetTitle(oss.str());

	wnd.Gfx().EndFrame();
}
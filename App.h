#pragma once

#include "GameWindow.h"
#include "Timer.h"

class App
{
public:
	App();
	//Master Frame /Message Loop
	int Go();

private:
	void DoFrame();
private:
	Window wnd;
	Timer tmr;
};
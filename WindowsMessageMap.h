#pragma once
#include "WindowDotHFix.h"
#include "GameWindow.h"
#include <unordered_map>

class WindowsMessageMap
{
public:
	WindowsMessageMap() noexcept;
	std::string operator() (DWORD msg, LPARAM lp, WPARAM wp) const noexcept;

private:
	std::unordered_map<DWORD, std::string> map;
};
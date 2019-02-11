
#include <Windows.h>
#include "Window.h"

Window::Window(int width, int height)
{
	//Create a Window
	CreateWindow("", "Chapter 2",
		WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_VISIBLE,
		100,100,width,height,
		nullptr,nullptr,nullptr,nullptr);

}
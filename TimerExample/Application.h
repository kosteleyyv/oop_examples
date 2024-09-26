#pragma once

#include <iostream>
#include <conio.h>

#include "TickerControl.h"

class Application
{
public:
	static int showHelp();
	static int run(const char* timeString);
};


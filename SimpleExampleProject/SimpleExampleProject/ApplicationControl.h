#pragma once
#include "SheetSerializer.h"
#include "UIView.h"

class ApplicationControl 
{
	SheetModel sheet;
	UIView view;

	enum class CommandType {
		WAIT_FOR_STRING,
		WAIT_FOR_COMMAND_CHAR
	} mCurrentAppMode = CommandType::WAIT_FOR_STRING;

public:

	int run();
};


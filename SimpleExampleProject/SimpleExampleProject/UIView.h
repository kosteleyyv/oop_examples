#pragma once
#include <iomanip>
#include <conio.h>
#include <Windows.h>

#include "SheetModel.h"
#include "ApplicationResources.h"

class UIView  {	
	const char LINE_SYMBOL   = '+';
	const char BORDER_SYMBOL = '|';
	const int NAME_COLUMN_WIDTH_IN_SYMBOLS = 60;
	const int MARK_COLUMN_WIDTH_IN_SYMBOLS = 20;
	const int SELECTION_COLUMN_WIDTH_IN_SYMBOLS = 3;
	const int TABLE_COLUMN_WIDTH_IN_SYMBOLS = NAME_COLUMN_WIDTH_IN_SYMBOLS 
		                                    + MARK_COLUMN_WIDTH_IN_SYMBOLS 
		                                    + SELECTION_COLUMN_WIDTH_IN_SYMBOLS 
		                                    + 4;
	
	void clearOutAndInput() const;
	void drawLineBorder(int borderWidth) const;
	void drawCommandHelp() const;
	void drawTableRow(bool isSelected, std::string firstColumnText, std::string secondColumnText) const;
	void drawSheetTable(const SheetModel& sheet) const;
	void drawStatusPanel(std::string statusString) const;

public:
	UIView();

	const ApplicationResources resources;

	void drawWaitKeyCommand(const SheetModel& sheet, std::string statusString) const;
	void drawForWaitInputString(const SheetModel& sheet, std::string statusString) const;

	int waitKeyCommand() const ;
	std::string waitInputString() const;
};


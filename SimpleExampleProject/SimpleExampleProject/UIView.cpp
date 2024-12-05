#include "UIView.h"

void UIView::drawLineBorder(int borderWidth) const {

	std::cout << BORDER_SYMBOL;
	for (int i = 1; i < borderWidth - 1; std::cout << LINE_SYMBOL, ++i);
	std::cout << BORDER_SYMBOL;

	std::cout << std::endl;
}

void UIView::drawCommandHelp() const {
	std::cout << "\t\t" << resources.helpHeaderText << std::endl;

	for (int i = 0; i < 9; i++) {
		std::cout << std::string("\t\t\"") 
			<< (char)resources.keyCommandSymbols[i]
			<< "\" - " 
			<< resources.helpKeyCommandManualStrings[i] 
			<< std::endl;
	}

	drawLineBorder(TABLE_COLUMN_WIDTH_IN_SYMBOLS);
}

void UIView::drawTableRow(bool isSelected, std::string firstColumnText, std::string secondColumnText) const {

	std::cout << std::internal;

	std::cout << BORDER_SYMBOL;

	std::cout << std::setw(SELECTION_COLUMN_WIDTH_IN_SYMBOLS);
	if (isSelected) {
		std::cout << "*";
	}
	else {
		std::cout << " ";
	}
	std::cout << BORDER_SYMBOL;

	std::cout << std::left;

	std::cout << std::setw(NAME_COLUMN_WIDTH_IN_SYMBOLS);
	std::cout << firstColumnText;

	std::cout << BORDER_SYMBOL;

	std::cout << std::setw(MARK_COLUMN_WIDTH_IN_SYMBOLS);
	std::cout << secondColumnText;

	std::cout << BORDER_SYMBOL;

	std::cout << std::endl;
}

void UIView::drawSheetTable(const SheetModel& sheet) const {

	drawLineBorder(TABLE_COLUMN_WIDTH_IN_SYMBOLS);

	std::cout << std::left;

	std::cout << BORDER_SYMBOL;

	std::cout << std::setw(TABLE_COLUMN_WIDTH_IN_SYMBOLS - 2);
	std::cout << resources.groupNumberHeaderText + sheet.getGroupName();
	std::cout << BORDER_SYMBOL;
	std::cout << std::endl;

	drawLineBorder(TABLE_COLUMN_WIDTH_IN_SYMBOLS);

	drawTableRow(false,
		         resources.nameHeaderText,
		         resources.markHeaderText);

	drawLineBorder(TABLE_COLUMN_WIDTH_IN_SYMBOLS);

	for (int i = 0; i < sheet.getRecordSize(); i++) {
		drawTableRow(i == sheet.getSelectedRecordIndex(),
			sheet.at(i).getFullName(),
			sheet.at(i).getMark());
	}

	if (sheet.getRecordSize() == 0) {
		drawTableRow( false, "",                        "");
		drawTableRow( true, resources.emptySheetText , "" );
		drawTableRow( false, "" ,                       "");
	}

	drawLineBorder(TABLE_COLUMN_WIDTH_IN_SYMBOLS);
}

void UIView::drawStatusPanel(std::string statusString) const {
	std::cout << statusString << std::endl;
}

void UIView::clearOutAndInput() const {
	system("cls||clear");
}

UIView::UIView() {
	clearOutAndInput();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
}

void UIView::drawWaitKeyCommand(const SheetModel& sheet, std::string statusString) const {
	clearOutAndInput();
	drawSheetTable(sheet);
	drawCommandHelp();
	drawStatusPanel(statusString);
}

void UIView::drawForWaitInputString(const SheetModel& sheet, std::string statusString) const {
	clearOutAndInput();
	drawSheetTable(sheet);
	drawStatusPanel(statusString);
}

int UIView::waitKeyCommand() const {
	while (!_kbhit());	
	return _getch();
}

std::string UIView::waitInputString() const {	
	std::string inputString;
	std::getline(std::cin, inputString, '\n');

	return inputString;
}

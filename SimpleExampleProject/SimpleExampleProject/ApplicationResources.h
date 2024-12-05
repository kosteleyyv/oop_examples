#pragma once
#include <string>
class ApplicationResources
{
	//E:\Текущие студенты\практика 4\SimpleExampleProject\SimpleExampleProject\542_1.csv
public:
	enum CommandCharType {
		OPEN_FILE = 'o',
		OPEN_FILE_RUS = 'щ',
		MARK_NONE = '0',
		MARK_FAILTURE = '1',
		MARK_SATISFACTORY = '3',
		MARK_GOOD = '4',
		MARK_EXCELLENT = '5',
		SELECT_NEXT_RECORD = 's',
		SELECT_NEXT_RECORD_RUS = 'ы',
		SELECT_PREVIOUS_RECORD = 'w',
		SELECT_PREVIOUS_RECORD_RUS = 'ц',
		EXIT = 'e',
		EXIT_RUS = 'у'
	};
	static const int keyCommandsCount = 9;
	CommandCharType keyCommandSymbols[keyCommandsCount] = {
		CommandCharType::OPEN_FILE,
		CommandCharType::SELECT_NEXT_RECORD,
		CommandCharType::SELECT_PREVIOUS_RECORD,
		CommandCharType::EXIT,
		CommandCharType::MARK_NONE,
		CommandCharType::MARK_EXCELLENT,
		CommandCharType::MARK_GOOD,
		CommandCharType::MARK_SATISFACTORY,
		CommandCharType::MARK_FAILTURE
	};

	std::string helpKeyCommandManualStrings[keyCommandsCount] = {
		"open file",
		"next record",
		"previous record",
		"exit",
		"clear mark",
		"mark 5",
		"mark 4",
		"mark 3",
		"mark n/a"
	};

	std::string statusShouldEnterFilePath = "Enter file path to open: ";
	std::string helpHeaderText = "Press:";
	std::string groupNumberHeaderText = "Group number: ";
	std::string nameHeaderText = "Name";
	std::string markHeaderText = "Mark";
	std::string emptySheetText = "Sheet is empty";
};


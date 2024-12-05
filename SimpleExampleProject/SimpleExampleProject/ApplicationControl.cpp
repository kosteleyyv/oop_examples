#include "ApplicationControl.h"

int ApplicationControl::run() {

	std::string statusString = view.resources.statusShouldEnterFilePath;

	mCurrentAppMode = CommandType::WAIT_FOR_STRING;

	while (true) {
		switch (mCurrentAppMode) {
		case CommandType::WAIT_FOR_STRING:
		{
			view.drawForWaitInputString(sheet, statusString);
			std::string filePath = view.waitInputString();

			try {
				SheetSerializer::deserialize(filePath, sheet);
				statusString = "";
			}
			catch (std::invalid_argument exp) {
				statusString = exp.what();
			}
			catch (std::logic_error exp) {
				statusString = exp.what();
			}

			mCurrentAppMode = CommandType::WAIT_FOR_COMMAND_CHAR;
		}
		break;
		case CommandType::WAIT_FOR_COMMAND_CHAR:
			view.drawWaitKeyCommand(sheet, statusString);

			bool isWatingNextCommand = false;
			do {
				isWatingNextCommand = false;
				int commandByKeyInput = view.waitKeyCommand();

				auto command = (ApplicationResources::CommandCharType)commandByKeyInput;
				switch (command) {
				case ApplicationResources::CommandCharType::OPEN_FILE:
				case ApplicationResources::CommandCharType::OPEN_FILE_RUS:
					mCurrentAppMode = CommandType::WAIT_FOR_STRING;
					statusString = view.resources.statusShouldEnterFilePath;
					break;
				case ApplicationResources::CommandCharType::EXIT:
				case ApplicationResources::CommandCharType::EXIT_RUS:
					exit(0);
					break;
				case ApplicationResources::CommandCharType::SELECT_NEXT_RECORD:
				case ApplicationResources::CommandCharType::SELECT_NEXT_RECORD_RUS:
					sheet.next();
					break;
				case ApplicationResources::CommandCharType::SELECT_PREVIOUS_RECORD:
				case ApplicationResources::CommandCharType::SELECT_PREVIOUS_RECORD_RUS:
					sheet.previous();
					break;
				case ApplicationResources::CommandCharType::MARK_EXCELLENT:
				case ApplicationResources::CommandCharType::MARK_GOOD:
				case ApplicationResources::CommandCharType::MARK_SATISFACTORY:
				case ApplicationResources::CommandCharType::MARK_NONE:
				case ApplicationResources::CommandCharType::MARK_FAILTURE:
					try {
						SheetRecord::MarkType mark;
						switch (command) {
						case ApplicationResources::CommandCharType::MARK_EXCELLENT:
							mark = SheetRecord::MarkType::EXCELLENT;
							break;
						case ApplicationResources::CommandCharType::MARK_GOOD:
							mark = SheetRecord::MarkType::GOOD;
							break;
						case ApplicationResources::CommandCharType::MARK_SATISFACTORY:
							mark = SheetRecord::MarkType::SATISFACTORY;
							break;
						case ApplicationResources::CommandCharType::MARK_NONE:
							mark = SheetRecord::MarkType::NONE;
							break;
						case ApplicationResources::CommandCharType::MARK_FAILTURE:
							mark = SheetRecord::MarkType::FAILTURE;
							break;
						}
						sheet.at(sheet.getSelectedRecordIndex()).setMark(mark);
						statusString = "";
					}
					catch (std::out_of_range exp) {
						statusString = exp.what();
					}
					break;
				default: // недопустимая команда
					isWatingNextCommand = true;
					break;
				}
			} while (isWatingNextCommand);

			break;
		}

	}

	return 0;
}

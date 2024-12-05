#include "SheetSerializer.h"

 void SheetSerializer::deserialize(std::string filePath, SheetModel& oSheet) {

	int correctReadRecordsCount = 0;
	int allNotEmptyRecordsCount = 0;

	std::ifstream inStream(filePath);
	if (!inStream.is_open()) {
		inStream.close();
		throw std::invalid_argument(std::string("Problem with file. Entered file path: ") + filePath);
	}

	oSheet.clear();

	std::string textLine;

	std::getline(inStream, textLine);
	oSheet.setGroupName(textLine);

	while (std::getline(inStream, textLine)) {

		if (textLine.length() == 0) {
			continue;
		}
		++allNotEmptyRecordsCount;

		auto listParams = split(textLine, ';');

		try {
			switch (listParams.size())
			{
			case 3:
				oSheet.addRecord(listParams[0], listParams[1], listParams[2]);
				++correctReadRecordsCount;
				break;
			case 2:
				oSheet.addRecord(listParams[0], listParams[1]);
				++correctReadRecordsCount;
				break;
			}
		}
		catch (std::invalid_argument) {
			// TODO можно пояснить пользователю, в каких записях некорректные данные в файле
		}
	}

	inStream.close();

	if (correctReadRecordsCount != allNotEmptyRecordsCount) {
		throw std::logic_error(std::string("Deserialized ")
			+ std::to_string(correctReadRecordsCount)
			+ " records from "
			+ std::to_string(allNotEmptyRecordsCount));
	}
}

std::vector<std::string> SheetSerializer::split(const std::string& s, char delim) {
	// https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
	std::vector<std::string> result;
	std::stringstream ss(s);
	std::string item;

	while (getline(ss, item, delim)) {
		result.push_back(item);
	}

	return result;
}

#pragma once

#include <string>
#include <iostream>
#include "SheetRecord.h"

class SheetModel {
public:
	SheetModel(int pStudentRecordsCapacity = 20);

	void addRecord(std::string pSurname, std::string pName, std::string pMidlename = "");
	void setGroupName(std::string pGroupName);

	void clear();

	void next();
	void previous();

	SheetRecord& at(int index) const;
	int getRecordSize() const;
	std::string getGroupName() const;
	int getSelectedRecordIndex() const;

	~SheetModel();

private:
	SheetRecord* mStudentRecords = nullptr;
	int mStudentRecordsSize = 0;
	int mStudentRecordsCapacity = 20;
	std::string mGroupName;
	int mSelectedStudentRecordIndex = 0;

	static const int defaultStockSize_ = 1;
};


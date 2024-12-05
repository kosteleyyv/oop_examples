#include "SheetModel.h"

SheetModel::SheetModel(int pStudentRecordsCapacity)
	: mStudentRecordsCapacity(pStudentRecordsCapacity) {
	mStudentRecords = new SheetRecord[mStudentRecordsCapacity];
}

void SheetModel::addRecord( std::string pSurname, std::string pName, std::string pMidlename) {

	SheetRecord newRecord(pSurname, pName, pMidlename);

	if (mStudentRecordsCapacity - mStudentRecordsSize <= 0) {

		mStudentRecordsCapacity = mStudentRecordsSize + 1 + defaultStockSize_;

		SheetRecord* buffNewStudentRecords = new SheetRecord[mStudentRecordsCapacity];

		for (int i = 0; i < mStudentRecordsSize; i++) {
			buffNewStudentRecords[i] = at(i);
		}

		delete[] mStudentRecords;
		mStudentRecords = buffNewStudentRecords;
	}
	mStudentRecordsSize++;
	at(mStudentRecordsSize - 1) = newRecord;


}

void SheetModel::setGroupName(std::string pGroupName) {

	if (!pGroupName.length()) {
		throw std::invalid_argument(std::string("Non-empty string expected for GroupName. Actual param: ") + pGroupName);
	}

	mGroupName = pGroupName;
}

void SheetModel::clear() {
	mStudentRecordsSize = 0;
	mSelectedStudentRecordIndex = 0;
}

void SheetModel::next() {
	if (mSelectedStudentRecordIndex + 1 < mStudentRecordsSize) {
		++mSelectedStudentRecordIndex;
	}
}

void SheetModel::previous() {
	if (mSelectedStudentRecordIndex - 1 >= 0) {
		--mSelectedStudentRecordIndex;
	}
}

SheetRecord& SheetModel::at(int index) const {
	if (!(index >= 0 && index < mStudentRecordsSize)) {

		throw std::out_of_range(std::string("Index out of range.")
			+ "\n Expected positive less " + std::to_string(mStudentRecordsSize)
			+ "\n Actual : " + std::to_string(index));
	}

	return mStudentRecords[index];
}

int SheetModel::getRecordSize() const {
	return mStudentRecordsSize;
}

std::string SheetModel::getGroupName() const {
	return mGroupName;
}

int SheetModel::getSelectedRecordIndex() const {
	return mSelectedStudentRecordIndex;
}

SheetModel::~SheetModel() {
	if (mStudentRecords != nullptr) {
		delete[] mStudentRecords;
		mStudentRecords = nullptr;
		mStudentRecordsSize = 0;
		mStudentRecordsCapacity = 0;
	}
}

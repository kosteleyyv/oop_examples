#include "SheetRecord.h"

SheetRecord::SheetRecord( std::string pSurname, std::string pName, std::string pMidlename) {

	setFullName(pSurname, pName,  pMidlename);
}

std::string SheetRecord::getName() const {
	return mName;
}

std::string SheetRecord::getSurname() const {
	return mSurname;
}

std::string SheetRecord::getMiddleName() const {
	return mMiddlename;
}

std::string SheetRecord::getFullName() const {
	return mSurname + " " + mName + (mMiddlename.length() != 0 ? " " + mMiddlename : "");
}

void SheetRecord::setFullName(std::string pSurname, std::string pName, std::string pMiddlename) {

	checkParams(pName, pSurname, pMiddlename);
	
	mName = pName;
	mSurname = pSurname;
	mMiddlename = pMiddlename;
}

void SheetRecord::setName(std::string pName) {
	if (!pName.length()) {
		throw std::invalid_argument(std::string("Non-empty string expected for Name. Actual param: ") + pName);
	}

	mName = pName;
}

void SheetRecord::setSurname(std::string pSurname) {
	if (!pSurname.length()) {
		throw std::invalid_argument(std::string("Non-empty string expected for Name. Actual param: ") + pSurname);
	}

	mSurname = pSurname;
}

void SheetRecord::setMiddlename(std::string pMiddlename) {
	mMiddlename = pMiddlename;
}

void SheetRecord::setMark(MarkType pMark) {
	checkParams(pMark);
	mMark = pMark;
}

std::string SheetRecord::getMark() const{
	switch (mMark) {
	case MarkType::NONE:
		return " ";
	case MarkType::FAILTURE:
		return "n/a";
	case MarkType::SATISFACTORY:
		return "3";
	case MarkType::GOOD:
		return "4";
	case MarkType::EXCELLENT:
		return "5";
	}
	return " ";
}

void SheetRecord::checkParams(std::string pName, std::string pSurname, std::string pMiddlename) const {

	if (!(pName.length() || pSurname.length())) {

		throw std::invalid_argument(std::string("Non-empty string expected. Actual params:")
			+ "\n pName = \"" + pName
			+ "\n pSurname = \"" + pSurname
			+ "\n pMiddlename = \"" + pMiddlename);
	}
}

void SheetRecord::checkParams(MarkType pMark) const {

	if (!(pMark >= MarkType::NONE
		&& pMark <= MarkType::EXCELLENT
		&& pMark != MarkType(2))) {

		throw std::invalid_argument(std::string("Incorrect mark value. Actual int params: ") + std::to_string((int)pMark));
	}
}

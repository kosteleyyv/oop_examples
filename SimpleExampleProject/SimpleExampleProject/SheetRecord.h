#pragma once
#include <string>
#include <iostream>

class SheetRecord {
public:

	SheetRecord() = default;
	SheetRecord(const SheetRecord&) = default;
	SheetRecord(SheetRecord&&) = default;
	SheetRecord& operator = (const SheetRecord&) = default;
	SheetRecord& operator = (SheetRecord&&) = default;

	SheetRecord(std::string pSurname, std::string pName, std::string pMidlename = "");

	std::string getName() const;
	std::string getSurname() const;
	std::string getMiddleName() const;
	std::string getFullName() const;
	std::string getMark() const;

	void setFullName(std::string pName, std::string pSurname, std::string pMiddlename = "");
	void setName(std::string pName);
	void setSurname(std::string pSurname);
	void setMiddlename(std::string pMiddlename);

	enum class MarkType {
		NONE = 0,
		FAILTURE = 1,
		SATISFACTORY = 3,
		GOOD = 4,
		EXCELLENT = 5
	};

	void setMark(MarkType pMark);	

private:
	std::string mName;
	std::string mSurname;
	std::string mMiddlename;
	MarkType mMark = MarkType::NONE;

	void checkParams(std::string pName, std::string pSurname, std::string pMiddlename) const;
	void checkParams(MarkType pMark) const;
};


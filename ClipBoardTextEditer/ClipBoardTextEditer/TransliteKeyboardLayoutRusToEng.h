#pragma once

#include "BaseTransliteTextRusToEng.h"

/// ������� ��������� � ��������� �� �������� � ��������
class TransliteKeyboardLayoutRusToEng : public BaseTransliteTextRusToEng {

	/// ����� ������� ��������
	static const int TRANSLITE_LAYOUT_SYMBOLS_COUNT = 95;

	/// ������� ��������
	static const char* const transliteLayoutDictionary[TRANSLITE_LAYOUT_SYMBOLS_COUNT][2];

protected:
	// ���������������� ������, ������� ���������� ������ ������� ��������

	virtual int getDictionaryLenght() const override;
	virtual const char* const getSymbol(int index, DictionaryKeyTypes key) const override;

public:
	TransliteKeyboardLayoutRusToEng(TranslationDirection type);
};



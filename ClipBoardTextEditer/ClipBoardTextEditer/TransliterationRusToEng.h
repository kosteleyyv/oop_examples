#pragma once
#include "BaseTransliteTextRusToEng.h"

/// �������������� � ��������� �� �������� � ��������
class TransliterationRusToEng : public BaseTransliteTextRusToEng {

	/// ����� ������� ��������
	static const int TRANSLITERATION_SYMBOLS_COUNT = 66;
	/// ������� ��������
	static const char* const transliterationDictionary[TRANSLITERATION_SYMBOLS_COUNT][2];

protected:
	// ���������������� ������, ������� ���������� ������ ������� ��������

	virtual int getDictionaryLenght() const override;
	virtual const char* const getSymbol(int index, DictionaryKeyTypes key) const override;
public:
	TransliterationRusToEng(TranslationDirection type);
};


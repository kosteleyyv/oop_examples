#pragma once

#include "BaseTransliteTextRusToEng.h"

/// перевод раскладки с кириллицы на латиницу и наоборот
class TransliteKeyboardLayoutRusToEng : public BaseTransliteTextRusToEng {

	/// длина алфавит перевода
	static const int TRANSLITE_LAYOUT_SYMBOLS_COUNT = 95;

	/// алфавит перевода
	static const char* const transliteLayoutDictionary[TRANSLITE_LAYOUT_SYMBOLS_COUNT][2];

protected:
	// переопределяемые методы, которые возвращают нужную таблицу алфавита

	virtual int getDictionaryLenght() const override;
	virtual const char* const getSymbol(int index, DictionaryKeyTypes key) const override;

public:
	TransliteKeyboardLayoutRusToEng(TranslationDirection type);
};



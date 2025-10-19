#pragma once
#include "BaseTransliteTextRusToEng.h"

/// транслитерация с кириллицы на латиницу и наоборот
class TransliterationRusToEng : public BaseTransliteTextRusToEng {

	/// длина алфавит перевода
	static const int TRANSLITERATION_SYMBOLS_COUNT = 66;
	/// алфавит перевода
	static const char* const TRANSLITERATION_DICTIONARY[TRANSLITERATION_SYMBOLS_COUNT][2];

protected:
	// переопределяемые методы, которые возвращают нужную таблицу алфавита

	virtual int getDictionaryLenght() const override;
	virtual const char* const getSymbol(int index, DictionaryKeyTypes key) const override;
public:
	TransliterationRusToEng(TranslationDirection type);

};


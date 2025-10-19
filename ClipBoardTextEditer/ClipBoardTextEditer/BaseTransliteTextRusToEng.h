#pragma once

#include <vector>
#include "TextEditer.h"

/// базовый класс для перевода кириллических букв на латинские по какой-то логике
class BaseTransliteTextRusToEng : public TextEditer
{
public:
	/// типы направления перевода
	enum TranslationDirection { 
		RusToEng, 
		EngToRus 
	};

	BaseTransliteTextRusToEng(TranslationDirection type);

	/// <summary>
	/// преобразование строки по таблице из getSymbol
	/// </summary>
	/// <returns> преобразованная строка </returns>
	virtual string getEditionResult() const override;

protected:
	/// индекс языка в таблице
	enum DictionaryKeyTypes  {
		RUS, 
		ENG 
	};

	/// направление перевода
	TranslationDirection translationType;

	/// чистый метод для определения длины словаря - алфавита
	virtual int getDictionaryLenght() const = 0;

	/// чистый метод для извлечения буквы алфавита для языка под DictionaryKeyTypes
	virtual const char* const getSymbol(int index, DictionaryKeyTypes key) const = 0;
};


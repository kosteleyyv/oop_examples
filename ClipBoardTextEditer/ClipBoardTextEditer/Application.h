#pragma once

#include <locale>
#include <iostream>

#include "Clipboard.h"
#include "RemovingDoubleWhitespace.h"
#include "TransliteKeyboardLayoutRusToEng.h"
#include "TransliterationRusToEng.h"

/// UI-CLASS SINGLETON
class Application {

public:
	enum class Modes
	{
		/// замена двойных пробелов
		RemovingDoubleWhitespace,
		/// смена раскладки с кириллицы на латиницу
		TransliteKeyboardLayoutRusToEng,
		/// транслитерация с кириллицы на латиницу
		TransliterationRusToEng,
		/// смена раскладки с латиницы на кириллицу
		TransliteKeyboardLayoutEngToRus,
		/// транслитерация  с латиницы на кириллицу
		TransliterationEngToRus
	};

	/// режим запуска
	static Modes Mode;
	/// запуск
	static int run();

private:
	/// получение объекта для редактирования в текущем режиме
	static TextEditer* getTextEditer();
	
};





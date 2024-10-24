#include "BaseTransliteTextRusToEng.h"

 BaseTransliteTextRusToEng::BaseTransliteTextRusToEng(TranslationDirection type) : translationType(type), 
	                                                                               TextEditer() {
}

  string BaseTransliteTextRusToEng::getEditionResult() const {

	 string copy = text;
	 int dictionaryLenght = getDictionaryLenght(); // определяем длину словаря замены

	 for (int i = 0; i < dictionaryLenght; i++) { // проходим по алфавиту

		 switch (translationType) { // в соотвествии с направлением перевода
		 case BaseTransliteTextRusToEng::RusToEng:
			 replace(copy, getSymbol(i, RUS), getSymbol(i, ENG)); // заменяем символ алфавита с одного на другой по таблице
			 break;
		 case BaseTransliteTextRusToEng::EngToRus:
			 replace(copy, getSymbol(i, ENG), getSymbol(i, RUS));
			 break;
		 }

	 }
	 return copy;
 }

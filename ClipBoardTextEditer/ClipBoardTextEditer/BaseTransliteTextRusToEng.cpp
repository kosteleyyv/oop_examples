#include "BaseTransliteTextRusToEng.h"

 BaseTransliteTextRusToEng::BaseTransliteTextRusToEng(TranslationDirection type) : translationType(type), 
	                                                                               TextEditer() {
}

  string BaseTransliteTextRusToEng::getEditionResult() const {

	  std::vector<std::string> copy;
	  copy.resize(text.size());

	  for (int i = 0; i < text.size(); i++) {
		  copy[i] = text[i];
	  }

	 int dictionaryLenght = getDictionaryLenght(); // определяем длину словаря замены

	 for (int i = 0; i < text.size(); i++) {
		 for (int symbolIndex = 0; symbolIndex < dictionaryLenght; symbolIndex++) { // проходим по алфавиту

			 bool isBreak = false;

			 switch (translationType) { // в соотвествии с направлением перевода
			 case BaseTransliteTextRusToEng::RusToEng:		 

				 isBreak = replace(copy[i], getSymbol(symbolIndex, RUS), getSymbol(symbolIndex, ENG)); // заменяем символ алфавита с одного на другой по таблице
				 break;
			 case BaseTransliteTextRusToEng::EngToRus:
				 isBreak = replace(copy[i], getSymbol(symbolIndex, ENG), getSymbol(symbolIndex, RUS));
				 break;
			 }

			 if (isBreak) {
				 break;
			 }
		 }
	 }
	 std::string result;
	 for (int i = 0; i < text.size(); i++) {
		 result += copy[i];
	 }

	 return result;
 }

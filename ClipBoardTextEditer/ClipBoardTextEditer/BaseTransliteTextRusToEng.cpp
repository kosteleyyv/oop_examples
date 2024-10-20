#include "BaseTransliteTextRusToEng.h"

 BaseTransliteTextRusToEng::BaseTransliteTextRusToEng(TranslationDirection type) : translationType(type), 
	                                                                               TextEditer() {
}

  string BaseTransliteTextRusToEng::getEditionResult() const {

	 string copy = text;
	 int dictionaryLenght = getDictionaryLenght(); // ���������� ����� ������� ������

	 for (int i = 0; i < dictionaryLenght; i++) { // �������� �� ��������

		 switch (translationType) { // � ����������� � ������������ ��������
		 case BaseTransliteTextRusToEng::RusToEng:
			 replace(copy, getSymbol(i, RUS), getSymbol(i, ENG)); // �������� ������ �������� � ������ �� ������ �� �������
			 break;
		 case BaseTransliteTextRusToEng::EngToRus:
			 replace(copy, getSymbol(i, ENG), getSymbol(i, RUS));
			 break;
		 }

	 }
	 return copy;
 }

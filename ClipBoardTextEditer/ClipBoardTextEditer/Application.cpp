#include "Application.h"

Application::Modes Application::Mode = Application::Modes::TransliteKeyboardLayoutRusToEng;

 int Application::run() {

	setlocale(LC_ALL, "Russian");
	try {
		// извлекаем текст из буфера обмена
		string stringFromClipboard = Clipboard::getText();

		// определяем нужный объект для обработки по режиму запуска
		TextEditer* textEditer = getTextEditer();

		// передаем в него строку из буфера
		textEditer->setSourceText(stringFromClipboard);

		// получаем результат обработки
		string stringToClipboard = textEditer->getEditionResult();

		// возвращаем преобразованную строку в буфер обмена
		Clipboard::setText(stringToClipboard.c_str());

		cout << "Строка из буфера обмена: " << stringFromClipboard.c_str() << endl << endl;
		cout << "Строка в буфере обмена:  " << stringToClipboard.c_str() << endl;
	}
	catch (exception exp) {
		cout << "Ошибка: " << exp.what() << endl;
	}

	system("pause");
	return 0;
}

 TextEditer* Application::getTextEditer() {

	switch (Mode) {
	case Application::Modes::RemovingDoubleWhitespace:
		return new RemovingDoubleWhitespace();
	case Application::Modes::TransliteKeyboardLayoutRusToEng:
		return new TransliteKeyboardLayoutRusToEng(BaseTransliteTextRusToEng::TranslationDirection::RusToEng);
	case Application::Modes::TransliterationRusToEng:
		return new TransliterationRusToEng(BaseTransliteTextRusToEng::TranslationDirection::RusToEng);
	case Application::Modes::TransliteKeyboardLayoutEngToRus:
		return new TransliteKeyboardLayoutRusToEng(BaseTransliteTextRusToEng::TranslationDirection::EngToRus);
	case Application::Modes::TransliterationEngToRus:
		return new TransliterationRusToEng(BaseTransliteTextRusToEng::TranslationDirection::EngToRus);
	default:
		return nullptr;
	}
}

#include "Application.h"

Application::Modes Application::Mode = Application::Modes::TransliteKeyboardLayoutRusToEng;

 int Application::run() {

	setlocale(LC_ALL, "Russian");
	try {
		// ��������� ����� �� ������ ������
		string stringFromClipboard = Clipboard::getText();

		// ���������� ������ ������ ��� ��������� �� ������ �������
		TextEditer* textEditer = getTextEditer();

		// �������� � ���� ������ �� ������
		textEditer->setSourceText(stringFromClipboard);

		// �������� ��������� ���������
		string stringToClipboard = textEditer->getEditionResult();

		// ���������� ��������������� ������ � ����� ������
		Clipboard::setText(stringToClipboard.c_str());

		cout << "������ �� ������ ������: " << stringFromClipboard.c_str() << endl << endl;
		cout << "������ � ������ ������:  " << stringToClipboard.c_str() << endl;
	}
	catch (exception exp) {
		cout << "������: " << exp.what() << endl;
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

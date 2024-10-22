#include "Application.h"

Application::Modes Application::Mode = Application::Modes::TransliteKeyboardLayoutRusToEng;

 int Application::run() {

	setlocale(LC_ALL, "Russian");
	try {
		// èçâëåêàåì òåêñò èç áóôåðà îáìåíà
		string stringFromClipboard = Clipboard::getText();

		// îïðåäåëÿåì íóæíûé îáúåêò äëÿ îáðàáîòêè ïî ðåæèìó çàïóñêà
		TextEditer* textEditer = getTextEditer();

		// ïåðåäàåì â íåãî ñòðîêó èç áóôåðà
		textEditer->setSourceText(stringFromClipboard);

		// ïîëó÷àåì ðåçóëüòàò îáðàáîòêè
		string stringToClipboard = textEditer->getEditionResult();
		
		delete textEditer;
		
		// âîçâðàùàåì ïðåîáðàçîâàííóþ ñòðîêó â áóôåð îáìåíà
		Clipboard::setText(stringToClipboard.c_str());

		cout << "Ñòðîêà èç áóôåðà îáìåíà: " << stringFromClipboard.c_str() << endl << endl;
		cout << "Ñòðîêà â áóôåðå îáìåíà:  " << stringToClipboard.c_str() << endl;
	}
	catch (exception exp) {
		cout << "Îøèáêà: " << exp.what() << endl;
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

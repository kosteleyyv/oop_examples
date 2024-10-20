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
		/// ������ ������� ��������
		RemovingDoubleWhitespace,
		/// ����� ��������� � ��������� �� ��������
		TransliteKeyboardLayoutRusToEng,
		/// �������������� � ��������� �� ��������
		TransliterationRusToEng,
		/// ����� ��������� � �������� �� ���������
		TransliteKeyboardLayoutEngToRus,
		/// ��������������  � �������� �� ���������
		TransliterationEngToRus
	};

	/// ����� �������
	static Modes Mode;
	/// ������
	static int run();

private:
	/// ��������� ������� ��� �������������� � ������� ������
	static TextEditer* getTextEditer();
	
};





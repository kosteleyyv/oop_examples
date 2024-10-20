#pragma once
#include <Windows.h>
#include <string>

using namespace std;
/// класс для работы с буфером обмена
class Clipboard {
	static exception prepareException(string text);
public:
	/// забирает текст из буфера обмена
	static string getText();
	/// помещает текст в буфер обмена
	static void setText(const char* output);
};


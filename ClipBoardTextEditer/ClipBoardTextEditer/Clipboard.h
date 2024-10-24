#pragma once
#include <Windows.h>
#include <string>
#include <vector>
#include <locale>

using namespace std;
/// класс для работы с буфером обмена
class Clipboard {
	static exception prepareException(string text);

	// перевод из char* строки в wchar_t*
	static std::wstring ToWstring(std::string Str);

	// перевод из wchar_t* строки в char*
	static std::string ToString(std::wstring Str);
public:
	/// забирает текст из буфера обмена
	static string getText();

	/// помещает текст в буфер обмена
	static void setText(const char* output);
};


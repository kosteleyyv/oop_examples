#pragma once

#include <string>

using namespace std;

/// базовый классс для задачи редактирования текста: хранит текст, задает функцию поиска-и-замены
class TextEditer
{
protected:
	/// текст для редактирования
	string text;

	/// <summary> метод замены в строке вхождения подстроки другой строкой </summary>
	/// <param name="stringToReplace">редактируемая строка</param>
	/// <param name="from">подстрока, которая будет заменена</param>
	/// <param name="to">строка, на которую заменяем</param>
	/// <returns>было ли заменено хотя бы одно вхождение</returns>
	static bool replace(string& stringToReplace, const string& from, const string& to);

public:
	/// чистый метод, который в производных классах д.б. переопределен на логику обработки строки
	virtual string getEditionResult() const = 0;

	/// устанавливает исходную строку для редактирования
	void setSourceText(const string& text);

	/// получает исходную строку для редактирования
	string getSourceText() const;
};

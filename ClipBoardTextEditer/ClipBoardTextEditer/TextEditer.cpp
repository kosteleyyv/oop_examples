#include "TextEditer.h"


 bool TextEditer::replace(string& stringToReplace, const string& from, const string& to) {

	size_t start_pos = stringToReplace.find(from); // первое вхождение строки from

	if (start_pos == string::npos || from.compare(to) == 0) { // если оно не найдено
		return false;
	}

	while (start_pos != string::npos ) { // пока подстрока находится в строке
		stringToReplace.replace(start_pos, from.length(), to); // заменяем ее вхождение на другую строку
		start_pos = stringToReplace.find(from); // ищем следующее вхождение
	}

	return true; // хотя бы одно вхождение было
}

 void TextEditer::setSourceText(const string& text) {
	this->text = text;
}

 string TextEditer::getSourceText() const {
	return text;
}

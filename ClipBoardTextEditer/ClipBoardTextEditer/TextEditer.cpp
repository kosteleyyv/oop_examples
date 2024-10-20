#include "TextEditer.h"


 bool TextEditer::replace(string& stringToReplace, const string& from, const string& to) {

	size_t start_pos = stringToReplace.find(from); // ������ ��������� ������ from

	if (start_pos == string::npos || from.compare(to) == 0) { // ���� ��� �� �������
		return false;
	}

	while (start_pos != string::npos ) { // ���� ��������� ��������� � ������
		stringToReplace.replace(start_pos, from.length(), to); // �������� �� ��������� �� ������ ������
		start_pos = stringToReplace.find(from); // ���� ��������� ���������
	}

	return true; // ���� �� ���� ��������� ����
}

 void TextEditer::setSourceText(const string& text) {
	this->text = text;
}

 string TextEditer::getSourceText() const {
	return text;
}

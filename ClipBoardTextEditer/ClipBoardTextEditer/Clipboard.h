#pragma once
#include <Windows.h>
#include <string>

using namespace std;
/// ����� ��� ������ � ������� ������
class Clipboard {
	static exception prepareException(string text);
public:
	/// �������� ����� �� ������ ������
	static string getText();
	/// �������� ����� � ����� ������
	static void setText(const char* output);
};


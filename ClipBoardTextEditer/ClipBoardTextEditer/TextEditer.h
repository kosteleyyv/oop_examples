#pragma once

#include <string>

using namespace std;

/// ������� ������ ��� ������ �������������� ������: ������ �����, ������ ������� ������-�-������
class TextEditer
{
protected:
	/// ����� ��� ��������������
	string text;

	/// <summary> ����� ������ � ������ ��������� ��������� ������ ������� </summary>
	/// <param name="stringToReplace">������������� ������</param>
	/// <param name="from">���������, ������� ����� ��������</param>
	/// <param name="to">������, �� ������� ��������</param>
	/// <returns>���� �� �������� ���� �� ���� ���������</returns>
	static bool replace(string& stringToReplace, const string& from, const string& to);

public:
	/// ������ �����, ������� � ����������� ������� �.�. ������������� �� ������ ��������� ������
	virtual string getEditionResult() const = 0;

	/// ������������� �������� ������ ��� ��������������
	void setSourceText(const string& text);

	/// �������� �������� ������ ��� ��������������
	string getSourceText() const;
};

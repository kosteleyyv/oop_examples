#include "RemovingDoubleWhitespace.h"

 string RemovingDoubleWhitespace::getEditionResult() const {
	string copy = text; // �������� �������� ���� �������� ������
	replace(copy, "  ", " "); // ��������� ����� �������� ������  ��� ������ ���� �������� �� ����
	return copy;
}

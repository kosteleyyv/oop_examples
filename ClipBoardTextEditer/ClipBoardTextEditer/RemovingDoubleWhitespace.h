#pragma once
#include "TextEditer.h"

/// �����, ����������� ������ ������ �������� ������� �� ���� ������
class RemovingDoubleWhitespace : public TextEditer
{
public:

	virtual string getEditionResult() const override;
};

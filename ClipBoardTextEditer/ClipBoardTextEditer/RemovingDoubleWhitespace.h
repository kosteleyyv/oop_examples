#pragma once
#include "TextEditer.h"

/// класс, реализующий логику замены двойного пробела на один пробел
class RemovingDoubleWhitespace : public TextEditer
{
public:

	virtual string getEditionResult() const override;
};

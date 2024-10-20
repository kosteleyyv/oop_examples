#pragma once

#include "TextEditer.h"

/// ������� ����� ��� �������� ������������� ���� �� ��������� �� �����-�� ������
class BaseTransliteTextRusToEng : public TextEditer
{
public:
	/// ���� ����������� ��������
	enum TranslationDirection { 
		RusToEng, 
		EngToRus 
	};

	BaseTransliteTextRusToEng(TranslationDirection type);

	/// <summary>
	/// �������������� ������ �� ������� �� getSymbol
	/// </summary>
	/// <returns> ��������������� ������ </returns>
	virtual string getEditionResult() const override;

protected:
	/// ������ ����� � �������
	enum DictionaryKeyTypes  {
		RUS, 
		ENG };

	/// ����������� ��������
	TranslationDirection translationType;

	/// ������ ����� ��� ����������� ����� ������� - ��������
	virtual int getDictionaryLenght() const = 0;

	/// ������ ����� ��� ���������� ����� �������� ��� ����� ��� DictionaryKeyTypes
	virtual const char* const getSymbol(int index, DictionaryKeyTypes key) const = 0;
};


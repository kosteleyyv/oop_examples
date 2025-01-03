﻿#include "TransliterationRusToEng.h"

 int TransliterationRusToEng::getDictionaryLenght() const {
	return TRANSLITERATION_SYMBOLS_COUNT; 
}

 const char* const TransliterationRusToEng::getSymbol(int index, DictionaryKeyTypes key) const { 
	return transliterationDictionary[index][key];
}

 TransliterationRusToEng::TransliterationRusToEng(TranslationDirection type) : BaseTransliteTextRusToEng(type) {
}

/// алфавит перевода
const char* const TransliterationRusToEng::transliterationDictionary[TransliterationRusToEng::TRANSLITERATION_SYMBOLS_COUNT][2]{
		{"а","a"},     {"б","b"},     {"в","v"},
		{"г","g"},     {"д","d"},     {"е","e"},
		{"ё","e"},     {"ж","zh"},    {"з","z"},
		{"и","i"},     {"й","y"},     {"к","k"},
		{"л","l"},     {"м","m"},     {"н","n"},
		{"о","o"},     {"п","p"},     {"р","r"},
		{"с","s"},     {"т","t"},     {"у","u"},
		{"ф","f"},     {"х","kh"},    {"ц","ts"},
		{"ч","ch"},    {"ш","sh"},    {"щ","shch"},
		{"ъ","''"},    {"ы","yi"},    {"ь","'"},
		{"э","e"},     {"ю","yu"},    {"я","ya"},
		{"А","A"},     {"Б","B"},     {"В","V"},
		{"Г","G"},     {"Д","D"},     {"Е","E"},
		{"Ё","E"},     {"Ж","Zh"},    {"З","Z"},
		{"И","I"},     {"Й","Y"},     {"К","K"},
		{"Л","L"},     {"М","M"},     {"Н","N"},
		{"О","O"},     {"П","P"},     {"Р","R"},
		{"С","S"},     {"Т","T"},     {"У","U"},
		{"Ф","F"},     {"Х","Kh"},    {"Ц","Ts"},
		{"Ч","Ch"},    {"Ш","Sh"},    {"Щ","Shch"},
		{"Ъ","''"},    {"Ы","Yi"},    {"Ь","'"},
		{"Э","E"},     {"Ю","Yu"},    {"Я","Ya"}
};

#include "TransliterationRusToEng.h"

 int TransliterationRusToEng::getDictionaryLenght() const {
	return TRANSLITERATION_SYMBOLS_COUNT; 
}

 const char* const TransliterationRusToEng::getSymbol(int index, DictionaryKeyTypes key) const { 
	return transliterationDictionary[index][key];
}

 TransliterationRusToEng::TransliterationRusToEng(TranslationDirection type) : BaseTransliteTextRusToEng(type) {
}

/// ������� ��������
const char* const TransliterationRusToEng::transliterationDictionary[TransliterationRusToEng::TRANSLITERATION_SYMBOLS_COUNT][2]{
		{"�","a"},     {"�","b"},     {"�","v"},
		{"�","g"},     {"�","d"},     {"�","e"},
		{"�","e"},     {"�","zh"},    {"�","z"},
		{"�","i"},     {"�","y"},     {"�","k"},
		{"�","l"},     {"�","m"},     {"�","n"},
		{"�","o"},     {"�","p"},     {"�","r"},
		{"�","s"},     {"�","t"},     {"�","u"},
		{"�","f"},     {"�","kh"},    {"�","ts"},
		{"�","ch"},    {"�","sh"},    {"�","shch"},
		{"�","''"},    {"�","y"},     {"�","'"},
		{"�","e"},     {"�","yu"},    {"�","ya"},
		{"�","A"},     {"�","B"},     {"�","V"},
		{"�","G"},     {"�","D"},     {"�","E"},
		{"�","E"},     {"�","Zh"},    {"�","Z"},
		{"�","I"},     {"�","Y"},     {"�","K"},
		{"�","L"},     {"�","M"},     {"�","N"},
		{"�","O"},     {"�","P"},     {"�","R"},
		{"�","S"},     {"�","T"},     {"�","U"},
		{"�","F"},     {"�","Kh"},    {"�","Ts"},
		{"�","Ch"},    {"�","Sh"},    {"�","Shch"},
		{"�","''"},    {"�","Y"},     {"�","'"},
		{"�","E"},     {"�","Yu"},    {"�","Ya"}
};

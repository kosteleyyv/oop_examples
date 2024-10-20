#include "TransliteKeyboardLayoutRusToEng.h"

 int TransliteKeyboardLayoutRusToEng::getDictionaryLenght() const {
	 return TRANSLITE_LAYOUT_SYMBOLS_COUNT; 
 }

  const char* const TransliteKeyboardLayoutRusToEng::getSymbol(int index, DictionaryKeyTypes key) const { 
	 return transliteLayoutDictionary[index][key];
 }

  TransliteKeyboardLayoutRusToEng::TransliteKeyboardLayoutRusToEng(TranslationDirection type) : BaseTransliteTextRusToEng(type) {
 }


 const char* const TransliteKeyboardLayoutRusToEng::transliteLayoutDictionary[TransliteKeyboardLayoutRusToEng::TRANSLITE_LAYOUT_SYMBOLS_COUNT][2]{
		{"�","~"}, {"!","!"},  {"\"","@"},  {"�","#"}, {";","$"},
		{"%","%"}, {":","^"},  {"?","&"},   {"*","*"}, {"(","("},
		{")",")"}, {"_","_"},  {"+","+"},   {"�","Q"}, {"�","W"},
		{"�","E"}, {"�","R"},  {"�","T"},   {"�","Y"}, {"�","U"},
		{"�","I"}, {"�","O"},  {"�","P"},   {"�","{"}, {"�","}"},
		{"/","|"}, {"�","A"},  {"�","S"},   {"�","D"}, {"�","F"},
		{"�","G"}, {"�","H"},  {"�","J"},   {"�","K"}, {"�","L"},
		{"�",":"}, {"�","\""}, {"�","Z"},   {"�","X"}, {"�","C"},
		{"�","V"}, {"�","B"},  {"�","N"},   {"�","M"}, {"�","<"},
		{"�",">"}, {",","?"},  {"�","`"},   {"1","1"}, {"2","2"},
		{"3","3"}, {"4","4"},  {"5","5"},   {"6","6"}, {"7","7"},
		{"8","8"}, {"9","9"},  {"0","0"},   {"-","-"}, {"=","="},
		{"�","q"}, {"�","w"},  {"�","e"},   {"�","r"}, {"�","t"},
		{"�","y"}, {"�","u"},  {"�","i"},   {"�","o"}, {"�","p"},
		{"�","["}, {"�","]"},  {"\\","\\"}, {"�","a"}, {"�","s"},
		{"�","d"}, {"�","f"},  {"�","g"},   {"�","h"}, {"�","j"},
		{"�","k"}, {"�","l"},  {"�",";"},   {"�","'"}, {"�","z"},
		{"�","x"}, {"�","c"},  {"�","v"},   {"�","b"}, {"�","n"},
		{"�","m"}, {"�",","},  {"�","."},   {".","/"}, {" "," "}
 };
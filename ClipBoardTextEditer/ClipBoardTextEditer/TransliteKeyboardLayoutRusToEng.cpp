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
		{"¨","~"}, {"!","!"},  {"\"","@"},  {"¹","#"}, {";","$"},
		{"%","%"}, {":","^"},  {"?","&"},   {"*","*"}, {"(","("},
		{")",")"}, {"_","_"},  {"+","+"},   {"É","Q"}, {"Ö","W"},
		{"Ó","E"}, {"Ê","R"},  {"Å","T"},   {"Í","Y"}, {"Ã","U"},
		{"Ø","I"}, {"Ù","O"},  {"Ç","P"},   {"Õ","{"}, {"Ú","}"},
		{"/","|"}, {"Ô","A"},  {"Û","S"},   {"Â","D"}, {"À","F"},
		{"Ï","G"}, {"Ð","H"},  {"Î","J"},   {"Ë","K"}, {"Ä","L"},
		{"Æ",":"}, {"Ý","\""}, {"ß","Z"},   {"×","X"}, {"Ñ","C"},
		{"Ì","V"}, {"È","B"},  {"Ò","N"},   {"Ü","M"}, {"Á","<"},
		{"Þ",">"}, {",","?"},  {"¸","`"},   {"1","1"}, {"2","2"},
		{"3","3"}, {"4","4"},  {"5","5"},   {"6","6"}, {"7","7"},
		{"8","8"}, {"9","9"},  {"0","0"},   {"-","-"}, {"=","="},
		{"é","q"}, {"ö","w"},  {"ó","e"},   {"ê","r"}, {"å","t"},
		{"í","y"}, {"ã","u"},  {"ø","i"},   {"ù","o"}, {"ç","p"},
		{"õ","["}, {"ú","]"},  {"\\","\\"}, {"ô","a"}, {"û","s"},
		{"â","d"}, {"à","f"},  {"ï","g"},   {"ð","h"}, {"î","j"},
		{"ë","k"}, {"ä","l"},  {"æ",";"},   {"ý","'"}, {"ÿ","z"},
		{"÷","x"}, {"ñ","c"},  {"ì","v"},   {"è","b"}, {"ò","n"},
		{"ü","m"}, {"á",","},  {"þ","."},   {".","/"}, {" "," "}
 };
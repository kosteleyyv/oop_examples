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
		{"Ё","~"}, {"!","!"},  {"\"","@"},  {"№","#"}, {";","$"},
		{"%","%"}, {":","^"},  {"?","&"},   {"*","*"}, {"(","("},
		{")",")"}, {"_","_"},  {"+","+"},   {"Й","Q"}, {"Ц","W"},
		{"У","E"}, {"К","R"},  {"Е","T"},   {"Н","Y"}, {"Г","U"},
		{"Ш","I"}, {"Щ","O"},  {"З","P"},   {"Х","{"}, {"Ъ","}"},
		{"/","|"}, {"Ф","A"},  {"Ы","S"},   {"В","D"}, {"А","F"},
		{"П","G"}, {"Р","H"},  {"О","J"},   {"Л","K"}, {"Д","L"},
		{"Ж",":"}, {"Э","\""}, {"Я","Z"},   {"Ч","X"}, {"С","C"},
		{"М","V"}, {"И","B"},  {"Т","N"},   {"Ь","M"}, {"Б","<"},
		{"Ю",">"}, {",","?"},  {"ё","`"},   {"1","1"}, {"2","2"},
		{"3","3"}, {"4","4"},  {"5","5"},   {"6","6"}, {"7","7"},
		{"8","8"}, {"9","9"},  {"0","0"},   {"-","-"}, {"=","="},
		{"й","q"}, {"ц","w"},  {"у","e"},   {"к","r"}, {"е","t"},
		{"н","y"}, {"г","u"},  {"ш","i"},   {"щ","o"}, {"з","p"},
		{"х","["}, {"ъ","]"},  {"\\","\\"}, {"ф","a"}, {"ы","s"},
		{"в","d"}, {"а","f"},  {"п","g"},   {"р","h"}, {"о","j"},
		{"л","k"}, {"д","l"},  {"ж",";"},   {"э","'"}, {"я","z"},
		{"ч","x"}, {"с","c"},  {"м","v"},   {"и","b"}, {"т","n"},
		{"ь","m"}, {"б",","},  {"ю","."},   {".","/"}, {" "," "}
 };
#include "Clipboard.h"

 exception Clipboard::prepareException(string text) {
	return exception((text 
		              + ". Код ошибки: " 
		              + to_string(GetLastError())).c_str());
}

 string Clipboard::getText() {

	 if (!OpenClipboard(NULL)) { // открываем буфер обмена
		 throw prepareException("Невозможно открыть буфер обмена");
	 }
	 // извлечение текста из глобальной памяти - общей памяти между приложениями в т.ч. с буфером обмена
	 HANDLE hData = GetClipboardData(CF_UNICODETEXT);
	 if (hData == NULL) {
		 throw prepareException("Буфер обмена не содержит текст");
	 }
	// блокируем память для единоличного пользования
	 wchar_t* pszText = (wchar_t*)GlobalLock(hData);
	 if (pszText == NULL) {
		 throw prepareException("Невозможно залочить глобальную память");
	 }
	 // копируем себе строку
	 wstring text(pszText);
	 // разблокируем память
	 GlobalUnlock(hData);
	 CloseClipboard(); // закрываем буфер обмена

	 string str = ToString(text); // переводим из Unicode
	 return str;
 }

 void Clipboard::setText(const char* output)
 {
	 wstring wcharStr = ToWstring(string(output)); // переводим в Unicode

	 // готовим глобальную память для обмена данными между приложмениями
	 const size_t len = (wcharStr.size() + 1) * 2;
	 HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);

	 if (hMem == NULL) {
		 throw prepareException("Невозможно захватить глобальную память");
	 }
	 // блокируем память для единоличного пользования
	 char* pszText = (char*)GlobalLock(hMem);
	 if (pszText == NULL) {
		 throw prepareException("Невозможно залочить глобальную память");
	 }
	 // копируем в нее строку
	 memcpy(pszText, wcharStr.c_str(), len);
	 // разблокируем память
	 GlobalUnlock(hMem);

	 if (hMem == NULL) {
		 throw prepareException("Невозможно залочить глобальную память");
	 }
	 // открываем буфер обмена
	 if (!OpenClipboard(NULL)) {
		 throw prepareException("Невозможно открыть буфер обмена");
	 }
	 // очищаем его
	 if (!EmptyClipboard()) {
		 throw prepareException("Невозможно очистить буфер обмена");
	 }
	 // помещаем туда строку
	 HANDLE hData = SetClipboardData(CF_UNICODETEXT, hMem);
	 if (hData == NULL) {
		 throw prepareException("Не удалось поместить текст в буфер обмена");
	 }
	 CloseClipboard(); // закрываем буфер обмена
 }

 inline std::wstring Clipboard::ToWstring(std::string Str) {
	 std::vector<wchar_t> buf(Str.size());
	 std::use_facet<std::ctype<wchar_t>>(std::locale("")).widen(Str.data(),
		 Str.data() + Str.size(),
		 buf.data());
	 return std::wstring(buf.data(), buf.size());
 }

 inline std::string Clipboard::ToString(std::wstring Str) {
	 std::string Result;

	 // UTF-8
	 std::vector<char> Bufer(Str.size());
	 std::use_facet<std::ctype<wchar_t>>(std::locale("")).narrow(Str.data(), Str.data() + Str.size(), '?', Bufer.data());
	 Result = std::string(Bufer.data(), Bufer.size());

	 // ANSI
	 //	int sz = WideCharToMultiByte(CP_ACP, 0, &Str[0], (int)Str.size(), 0, 0, 0, 0);
	 //	Result = std::string(sz, 0);
	 //	WideCharToMultiByte(CP_ACP, 0, &Str[0], (int)Str.size(), &Result[0], sz, 0, 0);

	 return Result;
 }

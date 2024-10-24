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
	 HANDLE hData = GetClipboardData(CF_TEXT);
	 if (hData == NULL) {
		 throw prepareException("Буфер обмена не содержит текст");
	 }
	// блокируем память для единоличного пользования
	 char* pszText = (char*)GlobalLock(hData);
	 if (pszText == NULL) {
		 throw prepareException("Невозможно залочить глобальную память");
	 }
	 // копируем себе строку
	 string text(pszText);
	 // разблокируем память
	 GlobalUnlock(hData);
	 CloseClipboard(); // закрываем буфер обмена

	 return pszText;
 }

 void Clipboard::setText(const char* output)
 {
	 // готовим глобальную память для обмена данными между приложмениями
	 const size_t len = strlen(output) + 1;
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
	 memcpy(pszText, output, len);
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
	 HANDLE hData = SetClipboardData(CF_TEXT, hMem);
	 if (hData == NULL) {
		 throw prepareException("Не удалось поместить текст в буфер обмена");
	 }
	 CloseClipboard(); // закрываем буфер обмена
 }

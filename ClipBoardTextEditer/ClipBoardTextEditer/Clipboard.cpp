#include "Clipboard.h"

 exception Clipboard::prepareException(string text) {
	return exception((text 
		              + ". ��� ������: " 
		              + to_string(GetLastError())).c_str());
}

 string Clipboard::getText() {

	 if (!OpenClipboard(NULL)) { // ��������� ����� ������
		 throw prepareException("���������� ������� ����� ������");
	 }
	 // ���������� ������ �� ���������� ������ - ����� ������ ����� ������������ � �.�. � ������� ������
	 HANDLE hData = GetClipboardData(CF_TEXT);
	 if (hData == NULL) {
		 throw prepareException("����� ������ �� �������� �����");
	 }
	// ��������� ������ ��� ������������ �����������
	 char* pszText = (char*)GlobalLock(hData);
	 if (pszText == NULL) {
		 throw prepareException("���������� �������� ���������� ������");
	 }
	 // �������� ���� ������
	 string text(pszText);
	 // ������������ ������
	 GlobalUnlock(hData);
	 CloseClipboard(); // ��������� ����� ������

	 return pszText;
 }

 void Clipboard::setText(const char* output)
 {
	 // ������� ���������� ������ ��� ������ ������� ����� �������������
	 const size_t len = strlen(output) + 1;
	 HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);

	 if (hMem == NULL) {
		 throw prepareException("���������� ��������� ���������� ������");
	 }
	 // ��������� ������ ��� ������������ �����������
	 char* pszText = (char*)GlobalLock(hMem);
	 if (pszText == NULL) {
		 throw prepareException("���������� �������� ���������� ������");
	 }
	 // �������� � ��� ������
	 memcpy(pszText, output, len);
	 // ������������ ������
	 GlobalUnlock(hMem);

	 if (hMem == NULL) {
		 throw prepareException("���������� �������� ���������� ������");
	 }
	 // ��������� ����� ������
	 if (!OpenClipboard(NULL)) {
		 throw prepareException("���������� ������� ����� ������");
	 }
	 // ������� ���
	 if (!EmptyClipboard()) {
		 throw prepareException("���������� �������� ����� ������");
	 }
	 // �������� ���� ������
	 HANDLE hData = SetClipboardData(CF_TEXT, hMem);
	 if (hData == NULL) {
		 throw prepareException("�� ������� ��������� ����� � ����� ������");
	 }
	 CloseClipboard(); // ��������� ����� ������
 }

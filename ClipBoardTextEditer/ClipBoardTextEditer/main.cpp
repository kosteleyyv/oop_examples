// ClipBoardTextEditer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Application.h"

int main()
{
    // текущий режим запуска
    Application::Mode = Application::Modes::TransliterationRusToEng;

    return Application::run();
}


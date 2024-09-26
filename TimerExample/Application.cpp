#include "Application.h"



int Application::showHelp()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "Приложение таймер"
		<< std::endl
		<< "В качестве аргумента командной строки передается время выполнения в формате HH:SS."
		<< std::endl
		<< "Максимальное время таймера 60 минут 60 секунд."
		<< std::endl;

	system("pause");
	return 0;
}

int Application::run(const char* timeString)
{
	setlocale(LC_ALL, "Russian");

	try
	{
		TickerTime tickTime = TickerTime::fromString(timeString);

		TickerControl tickerControl;
		tickerControl.setTimeDuration(tickTime);

		std::cout << "Секундомер запущен на ";
		tickTime.showTime(std::cout);

		tickerControl.init();

		while (!_kbhit() && !tickerControl.isStop())
		{
			tickerControl.showRemainingTime(std::cout);
			tickerControl.makeTick();
		}		
	}
	catch (std::exception exp)
	{
		std::cout << " --- Ошибка --- "
			<< std::endl
			<< exp.what()
			<< std::endl;

		system("pause");
		return -1;
	}

	std::cout << std::endl;
	system("pause");
	return 0;
}

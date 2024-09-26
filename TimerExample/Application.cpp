#include "Application.h"



int Application::showHelp()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "���������� ������"
		<< std::endl
		<< "� �������� ��������� ��������� ������ ���������� ����� ���������� � ������� HH:SS."
		<< std::endl
		<< "������������ ����� ������� 60 ����� 60 ������."
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

		std::cout << "���������� ������� �� ";
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
		std::cout << " --- ������ --- "
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

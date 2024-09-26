#include "TickerTime.h"

TickerTime TickerTime::fromString(const char* inputstring)
{
	// формат ввода 00:00
	std::string time = inputstring;
	if (time.length() != 5 || time[2] != ':')
	{
		input_error(time);
	}

	char buffMinutes[3]{ time[0], time[1], '\0' };
	char buffSeconds[3]{ time[3], time[4], '\0' };

	for (int i = 0; i < 2; i++)
	{
		if (!isdigit(buffMinutes[i]) || !isdigit(buffSeconds[i]))
		{
			input_error(time);
		}
	}
	TickerTime extracter;

	extracter.Minutes = atoi(buffMinutes);
	extracter.Seconds = atoi(buffSeconds);

	bool isUncorrectMinutes = extracter.Minutes > MAX_MINUTES;
	bool isUncorrectSeconds = extracter.Seconds > MAX_SECONDS;

	if (isUncorrectMinutes || isUncorrectSeconds)
	{
		input_error(time);
	}

	return extracter;
}

 void TickerTime::showTime(std::ostream& out)
{
	out << std::setw(2)
		<< std::setfill('0')
		<< Minutes
		<< ":"
		<< std::setw(2)
		<< std::setfill('0')
		<< Seconds
		<< std::endl;
}



void TickerTime::input_error(const std::string& time)
{
	throw std::exception((std::string("Входной параметр должен иметь формат HH:SS. Пришла строка: ") + time).c_str());
}

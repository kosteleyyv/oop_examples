#pragma once

#include <string>
#include <iomanip>

class TickerTime
{
public:

	unsigned int Minutes = 0;
	unsigned int Seconds = 0;

	const static  unsigned int MAX_MINUTES = 60;
	const static  unsigned int MAX_SECONDS = 60;

	static TickerTime fromString(const char* inputstring);
	void showTime(std::ostream& out);


private:
	static void input_error(const std::string& time);
};


#include "TickerControl.h"

TickerControl::TickerControl() : tickSound(100, 100), stopSound(300, 1000) {}

bool TickerControl::isStop() const
{
	return currentTimeSec == STOP_VALUE;
}

int TickerControl::getRemainingTime() const
{
	return currentTimeSec;
}

void TickerControl::showRemainingTime(std::ostream& out) const
{
	unsigned minutes = currentTimeSec / 60;
	unsigned seconds = currentTimeSec - minutes * 60;
	out << "\r"
		<< std::setw(4)
		<< std::setfill('0')
		<< currentTimeSec
		<< " -- "
		<< std::setw(2)
		<< std::setfill('0')
		<< minutes
		<< ":"
		<< std::setw(2)
		<< std::setfill('0')
		<< seconds
		<< " -- "
		/*<< std::endl*/;
}

void TickerControl::init()
{
	currentTimeSec = timeDurationSec;
}

void TickerControl::makeTick()
{
	if (!isStop())
	{
		if (currentTimeSec == 0)
		{
			stopSound.make();
		}
		else
		{
			tickSound.make();

			Sleep(1000 - tickSound.getDurationMs());
		}

		currentTimeSec--;


	}
}

void TickerControl::setTimeDuration(const TickerTime& time)
{
	setTimeDuration(time.Minutes, time.Seconds);
}

inline void TickerControl::setTimeDuration(const int& minutes, const int& seconds)
{
	bool isUncorrectMinutes = minutes > TickerTime::MAX_MINUTES;
	bool isUncorrectSeconds = seconds > TickerTime::MAX_SECONDS;

	if (isUncorrectMinutes || isUncorrectSeconds)
	{
		throw std::exception((std::string("Некорректный параметр:: пришло минуты - ")
			+ std::to_string(minutes)
			+ ", секунды - "
			+ std::to_string(seconds)).c_str());
	}

	timeDurationSec = (minutes * 60 + seconds);
}

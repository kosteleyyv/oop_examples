#pragma once

#include "Sound.h"
#include "TickerTime.h"


class TickerControl
{
public:
	TickerControl();

	bool isStop() const;

	int  getRemainingTime() const;
	void showRemainingTime(std::ostream& out) const;

	void setTimeDuration(const TickerTime& time);
	void setTimeDuration(const int& minutes, const int& seconds);

	void init();
	void makeTick();

private:
	Sound tickSound;
	Sound stopSound;

	int timeDurationSec = 0;
	int currentTimeSec = STOP_VALUE;

	const static int STOP_VALUE = -1;
};


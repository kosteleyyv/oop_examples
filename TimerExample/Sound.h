#pragma once

#include <string>
#include <Windows.h>

class Sound
{
public:
	Sound(const unsigned int& frequensyGz, const unsigned int& durationMs);

	void make() const;
	unsigned int getDurationMs() const;

private:
	unsigned int frequensyGz = 0;
	unsigned int durationMs  = 0;

	const static  unsigned int MIN_BEEP_MS = 100;
	const static  unsigned int MIN_FREQ_GZ = 50;
	const static  unsigned int MAX_BEEP_MS = 1000;
};


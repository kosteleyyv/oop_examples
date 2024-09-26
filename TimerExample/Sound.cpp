#include "Sound.h"

Sound::Sound(const unsigned int& frequensyGz, const unsigned int& durationMs)
{
	if (frequensyGz < MIN_FREQ_GZ)
	{
		throw std::exception((std::string("Частота должна быть больше")
			+ std::to_string(MIN_FREQ_GZ)
			+ ". Пришло: "
			+ std::to_string(frequensyGz)).c_str());
	}

	if (durationMs < MIN_BEEP_MS || MAX_BEEP_MS < durationMs)
	{
		throw std::exception((std::string("Время должно быть больше")
			+ std::to_string(MIN_BEEP_MS)
			+ ". Пришло: "
			+ std::to_string(durationMs)).c_str());
	}

	this->frequensyGz = frequensyGz;
	this->durationMs = durationMs;
}

void Sound::make() const
{
	Beep(frequensyGz, durationMs);
}

unsigned int Sound::getDurationMs() const
{
	return durationMs;
}

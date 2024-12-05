#pragma once
#include <vector>
#include <sstream>
#include <fstream>
#include "SheetModel.h"

class SheetSerializer
{
public:
	static void deserialize(std::string filePath, SheetModel& oSheet);
private:
	static std::vector<std::string> split(const std::string& s, char delim);
};


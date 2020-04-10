#pragma once

#include <string>

using namespace std;

class PerfumeryToEditNotSettedException
{
	string error_;
public:
	PerfumeryToEditNotSettedException()
	{
		error_ = "Парфюм для редактирования не установлен!";
	}

	const string getError()
	{
		return error_;
	}
};
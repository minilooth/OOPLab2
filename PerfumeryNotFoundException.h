#pragma once

#include <iostream>
#include <string>

using namespace std;

class PerfumeryNotFoundException
{
	string error_;
public:
	PerfumeryNotFoundException()
	{
		error_ = "—генерировано исключение! ѕарфюма с таким ид не существует!";
	}

	const string getError()
	{
		return error_;
	}
};
#pragma once

#include <string>

using namespace std;

class NullArgumentException
{
	string error_;
public:
	NullArgumentException()
	{
		error_ = "Аргумент не может быть пустым!";
	}

	const string getError()
	{
		return error_;
	}
};
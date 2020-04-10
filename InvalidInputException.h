#pragma once

#include <string>

using namespace std;

class InvalidInputException
{
	string error_;
public:
	InvalidInputException()
	{
		error_ = "Неверный ввод!";
	}

	const string getError()
	{
		return error_;
	}
};
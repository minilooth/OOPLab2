#pragma once

#include <iostream>
#include <string>

using namespace std;

class EmptyPerfumeryListException
{
	string error_;
public:
	EmptyPerfumeryListException()
	{
		error_ = "Список парфюма пуст!";
	}

	const string getError()
	{
		return error_;
	}
};
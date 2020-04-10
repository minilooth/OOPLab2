#pragma once

#include <iostream>
#include <string>

using namespace std;

class CustomerNotFoundException
{
	string error_;
public:
	CustomerNotFoundException()
	{
		error_ = " лиент с таким ид не найден!";
	}

	const string getError()
	{
		return error_;
	}
};
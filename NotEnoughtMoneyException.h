#pragma once

#include <iostream>
#include <string>

using namespace std;

class NotEnoughtMoneyException
{
	string error_;
public:
	NotEnoughtMoneyException()
	{
		error_ = "� ������� ������������ �������!";
	}

	const string getError()
	{
		return error_;
	}
};
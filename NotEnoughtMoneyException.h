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
		error_ = "У клиента недостаточно средств!";
	}

	const string getError()
	{
		return error_;
	}
};
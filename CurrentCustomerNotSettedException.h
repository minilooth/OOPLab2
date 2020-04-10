#pragma once

#include <iostream>
#include <string>

using namespace std;

class CurrentCustomerNotSettedException
{
	string error_;
public:
	CurrentCustomerNotSettedException()
	{
		error_ = "Текущий клиент не выбран!";
	}

	const string getError() { return error_; }
};
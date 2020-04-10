#pragma once

#include <iostream>
#include <string>

using namespace std;

class EmptyCustomerListException
{
	string error_;
public:
	EmptyCustomerListException()
	{
		error_ = "Список клиентов пуст!";
	}

	const string getError()
	{
		return error_;
	}
};
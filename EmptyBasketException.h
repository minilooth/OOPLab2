#pragma once

#include <iostream>
#include <string>

using namespace std;

class EmptyBasketException
{
	string error_;
public:
	EmptyBasketException()
	{
		error_ = "Корзина пуста!";
	}

	const string getError()
	{
		return error_;
	}
};
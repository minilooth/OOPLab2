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
		error_ = "������������� ����������! ������� � ����� �� �� ����������!";
	}

	const string getError()
	{
		return error_;
	}
};
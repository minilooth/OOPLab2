#pragma once

#include <string>

using namespace std;

class PerfumeryToEditNotSettedException
{
	string error_;
public:
	PerfumeryToEditNotSettedException()
	{
		error_ = "������ ��� �������������� �� ����������!";
	}

	const string getError()
	{
		return error_;
	}
};
#pragma once

#include <string>

using namespace std;

class NullArgumentException
{
	string error_;
public:
	NullArgumentException()
	{
		error_ = "�������� �� ����� ���� ������!";
	}

	const string getError()
	{
		return error_;
	}
};
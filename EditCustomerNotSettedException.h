#pragma once

#include <string>

using namespace std;

class EditCustomerNotSettedException
{
	string error_;
public:
	EditCustomerNotSettedException()
	{
		error_ = "������ ��� �������������� �� ����������!";
	}

	const string getError()
	{
		return error_;
	}
};


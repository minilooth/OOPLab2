#pragma once

#include <string>

using namespace std;

class EditCustomerNotSettedException
{
	string error_;
public:
	EditCustomerNotSettedException()
	{
		error_ = "Клиент для редактирования не установлен!";
	}

	const string getError()
	{
		return error_;
	}
};


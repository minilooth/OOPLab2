#pragma once

#include <iostream>
#include <string>

using namespace std;

class Human
{
protected:
	string firstname_;
	string middlename_;
	string lastname_;
public:
	Human() = default;
	Human(const string& firstname, const string& middlename, const string& lastname) : firstname_(firstname), middlename_(middlename), lastname_(lastname) {}

	void setFirstname(const string& firstname);
	void setMiddlename(const string& middlename);
	void setLastname(const string& lastname);

	string getFirstname();
	string getMiddlename();
	string getLastname();

	~Human() = default;
};


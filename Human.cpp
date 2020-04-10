#include "Human.h"

void Human::setFirstname(const string& firstname)
{
	firstname_ = firstname;
}

void Human::setMiddlename(const string& middlename)
{
	middlename_ = middlename;
}

void Human::setLastname(const string& lastname)
{
	lastname_ = lastname;
}

string Human::getFirstname()
{
	return firstname_;
}

string Human::getMiddlename()
{
	return middlename_;
}

string Human::getLastname()
{
	return lastname_;
}

#include "Customer.h"

Customer::Customer() 
{
	balance_ = 0.0;
}

Customer::Customer(const string& firstname, const string& middlename, const string& lastname, const string& telephone, const double& balance, const Basket& basket)
{
	firstname_ = firstname;
	middlename_ = middlename;
	lastname_ = lastname;
	telephone_ = telephone;
	basket_ = basket;
}

Customer::Customer(const string& firstname, const string& middlename, const string& lastname, const string& telephone, const double& balance)
{
	firstname_ = firstname;
	middlename_ = middlename;
	lastname_ = lastname;
	telephone_ = telephone;
	balance_ = balance;
}

void Customer::setTelephone(const string& telephone)
{
	telephone_ = telephone;
}

void Customer::setBalance(const double& balance)
{
	balance_ = balance;
}

void Customer::setBasket(const Basket& basket)
{
	basket_ = basket;
}

string Customer::getTelephone()
{
	return telephone_;
}

double Customer::getBalance()
{
	return balance_;
}

Basket& Customer::getBasket()
{
	return basket_;
}

void Customer::writeInFile(const string& filename)
{
	ofstream customersData;
	customersData.open(filename, ios::trunc);

	if (customersData.is_open())
	{
		customersData << this->firstname_ << ";"
				<< this->middlename_ << ";"
				<< this->lastname_ << ";"
				<< this->telephone_ << ";"
				<< this->balance_ << endl;
		customersData.close();
	}
}

ostream& operator<<(ostream& out, const Customer& customer)
{
	out << "|" << setw(13) << left << customer.firstname_
		<< "|" << setw(13) << left << customer.middlename_
		<< "|" << setw(12) << left << customer.lastname_
		<< "|" << setw(13) << left << customer.telephone_
		<< "|" << setw(12) << left << customer.balance_ 
		<< "|";
	return out;
}

Customer::~Customer() = default;
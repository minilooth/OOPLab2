#pragma once

#include <iomanip>
#include <string>
#include <fstream>

#include "Human.h"
#include "Basket.h"

using namespace std;

class Customer : public Human
{
	string telephone_;
	double balance_;
	Basket basket_;
public:
	Customer();
	Customer(const string& firstname, const string& middlename, const string& lastname, const string& telephone, const double& balance, const Basket& basket);
	Customer(const string& firstname, const string& middlename, const string& lastname, const string& telephone, const double& balance);

	void setTelephone(const string& telephone);
	void setBalance(const double& balance);
	void setBasket(const Basket& basket);

	string getTelephone();
	double getBalance();
	Basket& getBasket();

	void writeInFile(const string& filename);

	friend ostream& operator<<(ostream& out, const Customer& customer);

	~Customer();
};


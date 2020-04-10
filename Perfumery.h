#pragma once

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Perfumery
{
protected:
	string brand_;
	string flavor_;
	string aromaGroup_;
	string manufacturer_;
	string type_;
	double price_;
public:
	Perfumery();
	Perfumery(const string& brand, const string& flavor, const string& aromaGroup, const string& manufacturer, const double& price)
		: brand_(brand), flavor_(flavor), aromaGroup_(aromaGroup), manufacturer_(manufacturer), price_(price) {}
	explicit Perfumery(const Perfumery& perfumery);

	void setBrand(const string& brand);
	void setFlavor(const string& flavor);
	void setAromaGroup(const string& aromaGroup);
	void setManufacturer(const string& manufacturer);
	void setPrice(const double& price);

	string getBrand() const;
	string getFlavor() const;
	string getAromaGroup() const;
	string getManufacturer() const;
	string getType() const;
	double getPrice() const;

	friend ostream& operator<<(ostream& out, const Perfumery& perfumery);
	friend bool operator < (const Perfumery& comp1, const Perfumery& comp2);

	~Perfumery();
};


#include "Perfumery.h"

Perfumery::Perfumery()
{
	price_ = 0.0;
}

Perfumery::Perfumery(const Perfumery& perfumery)
{
	brand_ = perfumery.brand_;
	flavor_ = perfumery.flavor_;
	aromaGroup_ = perfumery.aromaGroup_;
	manufacturer_ = perfumery.manufacturer_;
	type_ = perfumery.type_;
	price_ = perfumery.price_;
}

void Perfumery::setBrand(const string& brand)
{
	brand_ = brand;
}

void Perfumery::setFlavor(const string& flavor)
{
	flavor_ = flavor;
}

void Perfumery::setAromaGroup(const string& aromaGroup)
{
	aromaGroup_ = aromaGroup;
}

void Perfumery::setManufacturer(const string& manufacturer)
{
	manufacturer_ = manufacturer;
}

void Perfumery::setPrice(const double& price)
{
	price_ = price;
}

string Perfumery::getBrand() const
{
	return brand_;
}

string Perfumery::getFlavor() const
{
	return flavor_;
}

string Perfumery::getAromaGroup() const
{
	return aromaGroup_;
}

string Perfumery::getManufacturer() const
{
	return manufacturer_;
}

string Perfumery::getType() const
{
	return type_;
}

double Perfumery::getPrice() const
{
	return price_;
}

ostream& operator<<(ostream& out, const Perfumery& perfumery)
{
	out << "|" << setw(18) << left << perfumery.brand_
		<< "|" << setw(13) << left << perfumery.type_
		<< "|" << setw(17) << left << perfumery.flavor_
		<< "|" << setw(21) << left << perfumery.aromaGroup_
		<< "|" << setw(18) << left << perfumery.manufacturer_
		<< "|" << setw(10) << left << perfumery.price_
		<< "|";
	return out;
}


bool operator<(const Perfumery& comp1, const Perfumery& comp2)
{
	return comp1.getPrice() < comp2.getPrice();
}

Perfumery::~Perfumery() = default;
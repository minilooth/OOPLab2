#include "MensPerfumes.h"

MensPerfumes::MensPerfumes()
{
	type_ = "Мужская";
}

MensPerfumes::MensPerfumes(Perfumery& perfumery)
{
	brand_ = perfumery.getBrand();
	flavor_ = perfumery.getFlavor();
	aromaGroup_ = perfumery.getAromaGroup();
	manufacturer_ = perfumery.getManufacturer();
	price_ = perfumery.getPrice();
	type_ = "Мужская";
}

void MensPerfumes::setType(const string& type)
{
	type_ = type;
}

string MensPerfumes::getType()
{
	return type_;
}

MensPerfumes::~MensPerfumes() = default;

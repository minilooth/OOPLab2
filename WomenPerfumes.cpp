#include "WomenPerfumes.h"

WomenPerfumes::WomenPerfumes()
{
	type_ = "�������";
}

WomenPerfumes::WomenPerfumes(Perfumery& perfumery)
{
	brand_ = perfumery.getBrand();
	flavor_ = perfumery.getFlavor();
	aromaGroup_ = perfumery.getAromaGroup();
	manufacturer_ = perfumery.getManufacturer();
	price_ = perfumery.getPrice();
	type_ = "�������";
}

void WomenPerfumes::setType(const string& type)
{
	type_ = type;
}

string WomenPerfumes::getType()
{
	return type_;
}

WomenPerfumes::~WomenPerfumes() = default;

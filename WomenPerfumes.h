#pragma once

#include "Perfumery.h"

class WomenPerfumes : public Perfumery
{
public:
	WomenPerfumes();
	WomenPerfumes(const string& brand, const string& flavor, const string& aromaGroup, const string& manufacturer, const double& price)
		: Perfumery(brand, flavor, aromaGroup, manufacturer, price) { type_ = "Женская"; }
	WomenPerfumes(Perfumery& perfumery);

	void setType(const string& type);

	string getType();

	~WomenPerfumes();
};


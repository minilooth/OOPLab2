#pragma once

#include "Perfumery.h"

class MensPerfumes : public Perfumery
{
public:
	MensPerfumes();
	MensPerfumes(const string& brand, const string& flavor, const string& aromaGroup, const string& manufacturer, const double& price)
		: Perfumery(brand, flavor, aromaGroup, manufacturer, price) {
		type_ = "Мужская";
	}
	MensPerfumes(Perfumery& perfumery);

	void setType(const string& type);

	string getType();

	~MensPerfumes();
};


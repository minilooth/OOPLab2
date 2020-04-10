#pragma once

#include <iostream>
#include <list>

#include "Perfumery.h"

#include "EmptyBasketException.h"

using namespace std;

class Basket
{
	list<Perfumery> perfumes_;
public:
	Basket();
	Basket(const list<Perfumery>& perfumes) : perfumes_(perfumes) {}

	void setPerfumes(const list<Perfumery>& perfumes);

	list<Perfumery>& getPerfumes();

	void addPerfume(const Perfumery& perfumes);

	friend ostream& operator<<(ostream & out, const Basket & basket);

	~Basket();
};


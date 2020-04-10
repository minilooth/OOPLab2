#include "Basket.h"

Basket::Basket() = default;

void Basket::setPerfumes(const list<Perfumery> & perfumes)
{
	perfumes_ = perfumes;
}

list<Perfumery>& Basket::getPerfumes()
{
	return perfumes_;
}

void Basket::addPerfume(const Perfumery& perfumes)
{
	perfumes_.push_back(perfumes);
}

ostream& operator<<(ostream& out, const Basket& basket)
{
	for (auto it = basket.perfumes_.begin(); it != basket.perfumes_.end(); it++)
	{
		out << *it << endl;
	}

	return out;
}

Basket::~Basket() = default;
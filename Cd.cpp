#include "Cd.h"

#include <iostream>


void Cd::report() const
{
	std::cout << "Performers: " << performers
		<< ", Label: " << label
		<< ", Selections: " << selections
		<< ", Playtime: " << playtime << "\n";
}


Cd& Cd::operator=(const Cd& d)
{
	performers = d.performers;
	label = d.label;
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}


void Classic::report() const
{
	std::cout << "Primary Work: " << primary << "\n";
	Cd::report();
}

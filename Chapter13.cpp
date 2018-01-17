#include <iostream>
#include <string>

#include "Port.h"
#include "Cd.h"

void showMenu();

void portCaller();
void cdCaller();

void bravo(const Cd& disk);

int main()
{
	showMenu();
	std::string in;
	while (std::getline(std::cin, in))
	{
		if (in == "q" || in == "Q")
			break;
		char cin = in[0];
		if (!(isdigit(cin)))
		{
			std::cout << "Please enter a valid option.\n";
			showMenu();
			continue;
		}
		int c = atoi(&cin);
		switch (c)
		{
		case 0: portCaller(); break;
		case 1: cdCaller(); break;
		default: std::cout << "Please enter a valid option.\n";
		}
		showMenu();
	}
	return 0;
}


void showMenu()
{
	std::cout << "0) Port\n1) Cd\nq) Quit\n> ";
}


void portCaller()
{
	Port p1("generic brand");
	std::cout << "p1: " << p1 << "\n";
	VintagePort* vp1 = new VintagePort("Old Port", 5, "Nicky Namy", 1998);
	std::cout << "vp1: " << *vp1 << "\n";
	delete vp1;
}


void cdCaller()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	Cd* pcd = &c1;

	std::cout << "Using object directly:\n";
	c1.report();
	c2.report();

	std::cout << "Using type cd* pointer to objects:\n";
	pcd->report();
	pcd = &c2;
	pcd->report();

	std::cout << "Calling a function with a Cd reference argument:\n";
	bravo(c1);
	bravo(c2);

	std::cout << "Testing assignment:\n";
	Classic copy;
	copy = c2;
	copy.report();
}


void bravo(const Cd& disk)
{
	disk.report();
}

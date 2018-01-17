#include "Port.h"

Port::Port(const char* br, const char* st, int b)
{
	brand = br;
	style = st;
	bottles = b;
}


Port::Port(const Port& p)
{
	brand = new char;
	brand = std::string(p.brand);
	style = p.style;
	bottles = p.bottles;
}


Port& Port::operator=(const Port& p)
{
	brand = p.brand;
	style = p.style;
	bottles = p.bottles;
	return *this;
}


Port& Port::operator+=(int b)
{
	bottles += b;
	return *this;
}


Port& Port::operator-=(int b)
{
	bottles -= b;
	return *this;
}


void Port::show() const
{
	std::cout << "Brand: " << brand
		<< "\nKind: " << style
		<< "\nBottles: " << bottles;
}


std::ostream& operator<<(std::ostream& os, const Port& p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}


VintagePort::VintagePort()
{
	nickname = "";
	year = 2018;
}


VintagePort::VintagePort(const VintagePort& vp)
{
	nickname = vp.nickname;
	year = vp.year;
}


VintagePort& VintagePort::operator=(const VintagePort& vp)
{
	nickname = vp.nickname;
	year = vp.year;
	return *this;
}


void VintagePort::show() const
{
	Port::show();
	std::cout << "\nNickname: " << nickname
		<< "\nYear: " << year;
}


std::ostream& operator<<(std::ostream& os, const VintagePort& vp)
{
	os << static_cast<const Port&>(vp) << ", " << vp.nickname << ", " << vp.year;
	return os;
}

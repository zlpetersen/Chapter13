#pragma once
#include <iostream>
#include <string>
class Port
{
private:
	std::string brand;
	std::string style;
	int bottles;
public:
	Port(const char* br = "none", const char* st = "none", int b = 0);
	Port(const Port& p);
	virtual ~Port() {  }
	Port& operator=(const Port& p);
	Port& operator+=(int b);
	Port& operator-=(int b);
	int bottleCount() const { return bottles; }
	virtual void show() const;
	friend std::ostream& operator<<(std::ostream& os, const Port& p);
};

class VintagePort : public Port
{
private:
	std::string nickname;
	int year;
public:
	VintagePort();
	VintagePort(const char* br, int b, const char* nn, int y) : Port(br, "none", b) { nickname = nn; year = y; }
	VintagePort(const VintagePort& vp);
	~VintagePort() {  }
	VintagePort& operator=(const VintagePort& vp);
	void show() const;
	friend std::ostream& operator<<(std::ostream& os, const VintagePort& vp);
};


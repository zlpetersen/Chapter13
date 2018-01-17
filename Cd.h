#pragma once
#include <string>
class Cd
{
private:
	std::string performers;
	std::string label;
	int selections;
	double playtime;
public:
	Cd(const std::string& s1, const std::string& s2, int n, double x) : performers(s1), label(s2), selections(n), playtime(x) {  }
	Cd(const Cd& d) : performers(d.performers), label(d.label), selections(d.selections), playtime(d.playtime) {  }
	Cd() : performers(""), label(""), selections(0), playtime(0) {  }
	~Cd() {  }
	virtual void report() const;
	Cd& operator=(const Cd& d);
};

class Classic : public Cd
{
private:
	std::string primary;
public:
	Classic(const std::string& p, const std::string& s1, const std::string& s2, int n, double x) : primary(p), Cd(s1, s2, n, x) {  }
	Classic() : primary(""), Cd() {  }
	virtual void report() const;
};


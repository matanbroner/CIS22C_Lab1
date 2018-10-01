#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
#include "string"
#include <iomanip>

class Currency
{
protected:
	std::string name, fraction;
	int whole, part;
public:
	Currency();
	Currency(std::string, int, int, std::string);
	virtual ~Currency();

	std::string getName() { return this->name; };
	std::string getFraction() {	return this->fraction; };
	int getWhole() { return this->whole; };
	int getPart() { return this->part; };
	void setName(std::string);
	void setFraction(std::string f) { this->fraction = f; };
	void setWhole(int w) { this->whole = w; };
	void setPart(int p) { this->part = p; };

	friend Currency operator+(const Currency&, const Currency&);
	friend Currency operator-(const Currency&, const Currency&);

	friend std::ostream& operator<<(std::ostream& stream, Currency&);
	friend std::istream& operator>>(std::istream& stream, Currency&);
};

class Dollar : public Currency
{
public:
	Dollar(Currency& a) : Currency("Dollar", a.getWhole(), a.getPart(), "cent") {}
	Dollar( int w, int p ) : Currency("Dollar", w, p, "cent") {}
};

class Euro : public Currency
{
public:
	Euro(Currency& a) : Currency("Euro", a.getWhole(), a.getPart(), "cent") {}
	Euro(int w, int p) : Currency("Euro", w, p, "cent") {}
};

class Yen : public Currency
{
public:
	Yen(Currency& a) : Currency("Yen", a.getWhole(), a.getPart(), "sen") {}
	Yen(int w, int p) : Currency("Yen", w, p, "sen") {}
};

class Rupee : public Currency
{
public:
	Rupee(Currency& a) : Currency("Rupee", a.getWhole(), a.getPart(), "paise") {}
	Rupee(int w, int p) : Currency("Rupee", w, p, "paise") {}
};

class Yuan : public Currency
{
public:
	Yuan(Currency& a) : Currency("Yuan", a.getWhole(), a.getPart(), "fen") {}
	Yuan(int w, int p) : Currency("Yuan", w, p, "fen") {}
};
#endif
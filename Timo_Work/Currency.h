#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
#include "string"

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
	int getWhole() { return this->whole; };
	int getPart() { return this->part; };

	friend Currency operator+(const Currency&, const Currency&);
	friend Currency operator-(const Currency&, const Currency&);

	friend std::ostream& operator<<(std::ostream& stream, const Currency&);
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
	Euro(int w, int p) : Currency("Euro", w, p, "cent") {}
};

class Yen : public Currency
{
public:
	Yen(int w, int p) : Currency("Yen", w, p, "sen") {}
};

class Rupee : public Currency
{
public:
	Rupee(int w, int p) : Currency("Rupee", w, p, "paise") {}
};

class Yuan : public Currency
{
public:
	Yuan(int w, int p) : Currency("Yuan", w, p, "fen") {}
};
#endif
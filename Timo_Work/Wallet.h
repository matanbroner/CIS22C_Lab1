#ifndef WALLET_H
#define WALLET_H

#include "Currency.h"

class Wallet
{
private:
	Currency* currencies[5];
public:
	Wallet();
	~Wallet();

	int exist(std::string); // check for currency existance of type name
	void add(Currency&);
	void subtract(Currency&); // can also be implemented in add -- disallow negative

	bool isEmpty(); // true if wallet empty
	std::string numEmpty(); // returns names of empty currencies
	void empty(); //empties wallet

	void outputCur(std::string);

	void test();
};

#endif

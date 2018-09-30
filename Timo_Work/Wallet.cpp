#include "Wallet.h"



Wallet::Wallet()
{
	for (int i = 0; i < 5; i++)
		currencies[i] = nullptr;
}


Wallet::~Wallet()
{
	for (int i = 0; i < 5; i++)
		if (currencies[i] != nullptr)
			delete currencies[i];
}

int Wallet::exist(std::string n)
{
	for (int i = 0; i < 5; i++) {
		if (currencies[i] != nullptr) {
			if (n == currencies[i]->getName()) {
				std::cout << "we found something at: " << i << std::endl;
				return i;
			}
		}
	}
	return -1;
}

void Wallet::add(Currency &a)
{
	int position = exist(a.getName());
	if ( position > -1 )
		*currencies[position] = *currencies[position] + a; // not sure if correct
	else if (a.getName() == "Dollar")
		currencies[position] = new Dollar( a ) ;
}

void Wallet::subtract(Currency &a)
{
	try {
		int position = exist(a.getName());
		if (position == -1)
			throw std::string("Input is invalid. Please try again.\n");

		*currencies[position] = *currencies[position] - a;
	} catch (std::string msg) {
		std::cout << "We broke :c " << msg << std::endl;
	}
}

bool Wallet::isEmpty()
{
	bool isEmpty = true;
	for (int i = 0; i < 5; i++) {
		if (currencies[i] != nullptr) {
			if (currencies[i]->getWhole() != 0 && currencies[i]->getPart() != 0)
				bool isEmpty = false;
		}
	}

	return isEmpty;
}

std::string Wallet::numEmpty()
{
	std::string empty;

	for (int i = 0; i < 5; i++) {
		if (currencies[i] == nullptr) 
			empty += currencies[i]->getName() + " ";
		else if (currencies[i]->getWhole() != 0 && currencies[i]->getPart() != 0)
			empty += currencies[i]->getName() + " ";
	}

	return empty;
}

void Wallet::empty()
{
	if (!isEmpty()) {
		std::cout << "Emptied wallet of: \n";

		for (int i = 0; i < 5; i++)
			if (currencies[i] != nullptr) {
				std::cout << currencies[i];
				delete currencies[i];
			}
	}
}

void Wallet::outputCur(std::string a)
{
	int position = exist(a);

	if (position > -1)
		std::cout << *currencies[position];
}

void Wallet::test()
{
	currencies[0] = new Dollar(5,10);
}

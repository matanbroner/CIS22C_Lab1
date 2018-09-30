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
				//std::cout << "we found something at: " << i << std::endl;
				return i;
			}
		}
	}
	return -1;
}

void Wallet::add(Currency &a)
{
	bool newCur = false;
	int position = exist(a.getName());
	if ( position > -1 )
		*currencies[position] = *currencies[position] + a; // not sure if correct
	else if (a.getName() == "Dollar") {
		currencies[0] = new Dollar(a);
		newCur = true;
	}
	else if (a.getName() == "Euro") {
		currencies[0] = new Euro(a);
		newCur = true;
	}
	else if (a.getName() == "Yen") {
		currencies[0] = new Yen(a);
		newCur = true;
	}
	else if (a.getName() == "Rupee") {
		currencies[0] = new Rupee(a);
		newCur = true;
	}
	else if (a.getName() == "Yuan") {
		currencies[0] = new Yuan(a);
		newCur = true;
	}


	if (newCur == false) {
		position = exist(a.getName());
		std::cout << "\nAdded " << a << "   to " << *currencies[position] << std::endl;
	}
	else {
		std::cout << "Added " << a << "   to wallet.\n";
	}
}

void Wallet::subtract(Currency &a)
{
	int position = exist(a.getName());

	std::cout << "Subtracting " << a << "       from " << *currencies[position] << std::endl;
	try {
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
				isEmpty = false;
		}
	}
	return isEmpty;
}

std::string Wallet::numEmpty()
{
	std::string empty;

	for (int i = 0; i < 5; i++) {
		if (currencies[i] == nullptr) {
			switch (i)
			{
			case 0:
				empty += "Dollar ";
				break;
			case 1:
				empty += "Euro ";
				break;
			case 2:
				empty += "Yen ";
				break;
			case 3:
				empty += "Rupee ";
				break;
			case 4: 
				empty += "Yuan ";
				break;
			}
		}
		else if (currencies[i]->getWhole() == 0 && currencies[i]->getPart() == 0)
			empty += currencies[i]->getName() +" ";
	}

	return empty;
}

void Wallet::empty()
{
	if (!isEmpty()) {
		std::cout << "Emptied wallet of: \n";

		for (int i = 0; i < 5; i++)
			if (currencies[i] != nullptr) {
				std::cout << *currencies[i];
				delete currencies[i];
				currencies[i] = nullptr;
			}
	}
}

void Wallet::outputCur(std::string a)
{
	int position = exist(a);

	if (position > -1)
		std::cout << *currencies[position];
	else
		std::cout << "There is currently none of currency type " << a << " in wallet.\n";
}

void Wallet::test()
{
	currencies[0] = new Dollar(5,10);
}

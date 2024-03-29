// main.cpp : Defines the entry point for the console application.
//

#include "Currency.h"
#include "Wallet.h"
#include <limits>

int menu();

int main()
{
	Wallet wallet;
	int option = -1;
	std::string name;
	Currency temp;
	do {
		option = menu();
		name = "";

		switch (option)
		{
		case 1:
			wallet.outputAll();
			break;
		case 2:
			std::cout << "\nType currency name to view: (Dollar, Euro, Yen, Rupee, Yuan)\n[?]: ";
			std::cin >> name;
			wallet.outputCur(name);
			break;
		case 3:
			std::cout << "\nType currency name and value to add: (Dollar, Euro, Yen, Rupee, Yuan)\n[?]: ";
			std::cin >> name;
			temp.setName(name);
			std::cin >> temp;
			wallet.add(temp);
			//wallet.outputCur(name);
			break;
		case 4:
			std::cout << "\nType currency name and value to withdraw: (Dollar, Euro, Yen, Rupee, Yuan)\n[?]: ";
			std::cin >> name;
			temp.setName(name);
			std::cin >> temp;
			wallet.subtract(temp);
			//wallet.outputCur(name);
			break;
		case 5:
			wallet.empty();
			break;
		}
		if (option != 6) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Press ENTER to continue...";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (option != 6);

    return 0;
}

int menu() {
	int input = -1;
	std::cout << "\nWallet options: \n"
		<< "[1] View wallet\n"
		<< "[2] View specific currency quantity\n"
		<< "[3] Add currency\n"
		<< "[4] Withdraw some currency\n"
		<< "[5] Withdraw ALL currency\n"
		<< "[6] Exit\n";

	bool errorNonInt = false;
	do {
		errorNonInt = false;
		try {
			std::cout << "[?]: ";
			std::cin >> input;
			if (std::cin.fail()) {	// catch nonint
				std::cin.clear();	// clear error flag
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// remove any extra characters if user typed more than one
				errorNonInt = true;	// used to avoid throwing multiple errors
				throw std::string("Input is invalid. Please try again with an integer value.\n");
				input = -1;
			}

			if (input > 6 || input < 1 && errorNonInt == false) {	// catch input out of range -- change 6 to max number of options
				input = -1;
				throw std::string("invalid number input out of range.\n");
			}
		}
		catch (std::string msg) {		//interpret exception from char string passed
			std::cout << "Error: " << msg << std::endl;
			errorNonInt = false;	// reset now that we've dealt with the error
		}
	} while (input == -1);

	return input;
}
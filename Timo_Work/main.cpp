// main.cpp : Defines the entry point for the console application.
//

#include "Currency.h"
#include "Wallet.h"


int main()
{
	Wallet test;
	
	Dollar dollar(5, 10);
	test.add(dollar);
	
	//test.outputCur("Dollar");

	//test.test();
	//test.outputCur("Dollar");
	test.add(dollar);
	//test.outputCur("Dollar");

	test.subtract(dollar);
	std::cout << "Current amount of Dollars: \n";  test.outputCur("Dollar"); std::cout << std::endl;

	std::string num = test.numEmpty();
	if (num != "")
		std::cout << "We have none of currencies: " << test.numEmpty() << "\n\n";

	test.empty();
	std::cout << "\nCurrent amount of Dollars: \n";  test.outputCur("Dollar"); std::cout << std::endl;
	std::cout << "We have none of currencies: " << test.numEmpty() << std::endl;

    return 0;
}


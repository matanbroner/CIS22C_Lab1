// main.cpp : Defines the entry point for the console application.
//

#include "Currency.h"
#include "Wallet.h"


int main()
{
	Wallet test;
	
	Dollar dollar(5, 10);
	//test.add(dollar); // doesnt work, I messed something up
	
	//test.outputCur("Dollar");

	test.test();
	test.outputCur("Dollar");

    return 0;
}


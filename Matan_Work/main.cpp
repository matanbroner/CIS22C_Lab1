//
//  main.cpp
//  CIS22C_Lab1
//
//  Created by Matan Broner on 9/27/18.
//  Copyright © 2018 Matan Broner. All rights reserved.
//

#include <iostream>
#include <stdlib.h>

#include "Wallet.h"

using namespace std;

int menuOptions();

int main(int argc, const char * argv[]) {
    Wallet wallet;
    int currIndex = 0;
    
    int menuOption = 0;
    cout <<"<<< Welcome to the CIS22C eWallet >>>" << endl;
    while (menuOption != 7)
    {
        menuOption = menuOptions();
        switch(menuOption)
        {
            case 1: wallet.getWalletInfo();
                break;
            case 2:
                currIndex = wallet.currencyIndexer();
                cout << *wallet[currIndex];
                break;
            case 3:
                currIndex = wallet.currencyIndexer();
                wallet.addCurrency(wallet[currIndex]);
                break;
            case 4:
                currIndex = wallet.currencyIndexer();
                wallet.subtractCurrency(wallet[currIndex]);
                break;
            case 5:
                wallet.zeroOut();
                break;
            case 6:
                wallet.userManual();
                break;
            case 7:
                cout << "Exiting eWallet..." << endl;
            default: cout << "Error occured with menu choice..." << endl;
        }
        cout << endl << endl;
        system("clear");
    }
    cout << "Thanks for using eWallet! Goodbye!" << endl;
    
    return 0;
}

int menuOptions()
{
    int menuOption = 0;
    cout << "Options for operations: " << endl;
    cout << "[1] -- View entire wallet status" << endl;
    cout << "[2] -- View individual currency status" << endl;
    cout << "[3] -- Add value to currency type" << endl;
    cout << "[4] -- Subtract value from currency type" << endl;
    cout << "[5] -- Zero out all currencies in your wallet" << endl;
    cout << "[6] -- Read manual for your eWallet" << endl;
    cout << "[7] -- Exit" << endl;
    
    do
    {
        cout << "--> ";
        cin >> menuOption;
    }
    while (menuOption < 1 || menuOption > 7);
    
    return menuOption;
}






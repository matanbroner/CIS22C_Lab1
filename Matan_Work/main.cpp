
/*
 CIS 22C Lab 1: Create a Wallet
 Matan Broner & Timo Bitterli
 
 Partner Rating (Matan for Timo): 0
 _________________________________________________________________________________________________________________
 This program is meant to simulate a pocketheld wallet used for 5 foreign currencies by a user
 The user has th option to view wallet and individual currency statuses, add currency values, subtract currency--
 values, zero out all currency values, and read a user manual.
 The program loops an options indexed menu with all of these actions and refuses out of bounds or illegal values,
 exception handling is implemented anywhere in the program where illegal values may be entered.
 The wallet is built using polymorphically contructed derived currency objects using a base Currency pointer array.
_________________________________________________________________________________________________________________
 
 Pseudocode:
 make Wallet --> wallet
 menuOption = 0
 currIndex = 0
 while menuOptions not equal 7
    menuOption = menuOptions() --> allows user to choose a task to complete as an indexed menu
    if:
    menuOption = 1 --> getWalletInfo --> presents currencies with nonzero values or says wallet is empty
    menuOption = 2 --> currIndex = currencyIndexer --> read out info about currency at index
    menuOption = 3 --> currIndex = currencyIndexer --> add currency at index chosen using addCurrency
    menuOption = 4 --> currIndex = currencyIndexer --> subtract currency at index chosen using subtractCurrency
    menuOption = 5 --> walletZeroOut --> all currency values in the wallet are set to 0
    menuOption = 6 --> userManual
    menuOption = 7 --> exit loop
 
    if menuOption does not equal 7:
        print "Press EXIT to continue..."
        wait for user to press enter key
        clear console
 print exiting statement
 return 0
 
 Wallet pseudocode:
    Construct 5 polymorphic derived Currency objects
    .
    .  --> main driver program acts on wallet
    .
    Delete each pointer for each Currency object
 */


#include <iostream>
#include <stdlib.h>

#include "Wallet.h"

using namespace std;

int menuOptions();

int main(int argc, const char * argv[]) {
    Wallet wallet;
    int currIndex = 0; // Used to choose a currency for action
    
    int menuOption = 0; // Used to pick an action on the Wallet
    cout <<"<<< Welcome to the CIS22C eWallet >>>" << endl;
    while (menuOption != 7) // 7 is the loop exiting index
    {
        menuOption = menuOptions();
        switch(menuOption)
        {
            case 1: wallet.getWalletInfo(); // States all nonzero currency values or empty wallet
                break;
            case 2:
                currIndex = wallet.currencyIndexer(); // User chooses a currency
                cout << *wallet[currIndex]; // Displays information about currency
                break;
            case 3:
                currIndex = wallet.currencyIndexer(); // User chooses a currency
                wallet.addCurrency(wallet[currIndex]);
                break;
            case 4:
                currIndex = wallet.currencyIndexer(); // User chooses a currency
                wallet.subtractCurrency(wallet[currIndex]);
                break;
            case 5:
                wallet.zeroOut(); // All currency values are set to 0 (if not already)
                break;
            case 6:
                wallet.userManual();
                break;
            case 7:
                break; // Exit
            default: cout << "Error occured with menu choice..." << endl;
        }
        cout << endl << endl;
        if (menuOption != 7) // Has user respond and clears console
        {
            cout << "Press ENTER to continue...";
            cin.get();
            cin.get();
            system("cls");
        }
    }
    cout << "Thanks for using eWallet! Goodbye!" << endl;
    
    system("pause");
    return 0;
}

int menuOptions()
{
    int menuOption = -1;
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
        try
        {
            cin >> menuOption;
            if (cin.fail()) // illegal value given
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // removes illegal value
                throw "Illegal value given, choose again.\n";
            }
            else if (menuOption < 1 || menuOption > 7) // out of bounds error
                throw "Out of bounds error, choose again.\n";
        }
        catch(char const* error) // catches string prompt
        {
            cout << error;
            menuOption = -1;
        }
    }
    while (menuOption == -1); // -1 is the loop exiting index
    
    return menuOption;
}






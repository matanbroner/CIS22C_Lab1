//
//  Wallet.h
//  CIS22C_Lab1
//
//  Created by Matan Broner on 9/29/18.
//  Copyright © 2018 Matan Broner. All rights reserved.
//

#ifndef Wallet_h
#define Wallet_h
#include "DerivedCurrencies.h"


class Wallet
{
private:
    Currency* currArr[5];
    const int NUMCURRS = 5;
public:
    Wallet();
    Currency* operator[](int i); // used to make calls directly to Wallet's array attribute based on index
    
    void getCurrInfo(); // uses Currency indexer to use overloaded << operator to display information
    
    /* Method displays all Currencies with nonzero value, and informs user if Wallet is completely empty
     Pre: none
     Post: none
     Return: none
     */
    void getWalletInfo();
    
    /* Method takes a Currency pointer and uses the overloaded += operator to add value to it
     Pre: Currency pointer --> one of the 5 currencies in the Wallet's array attribute
     Post: Currency object has value added
     Return: none
     */
    void addCurrency(Currency*);
    
    /* Method takes a Currency pointer and uses the overloaded -= operator to subtract value from it
     Pre: Currency pointer --> one of the 5 currencies in the Wallet's array attribute
     Post: Currency object has value subtracted
     Return: none
     */
    void subtractCurrency(Currency*);
    
    /* Method changes all nonzero Currency objects to 0 value and informs user how much was removed from each
     Pre: none
     Post: All objects in Wallet's array attribute have values set to 0
     Return: none
     */
    void zeroOut();
    
    /* Method checks if all objects in Wallet's array attribute have 0 value
     Pre: none
     Post: none
     Return: true or false
     */
    bool walletEmpty();
    void userManual(); // used to give user general info about Wallet's usage in driver program
    
    /* Method offers user a menu of availible currencies and has them choose one based on menu index
     Pre: none
     Post: none
     Return: integer index value
     */
    static int currencyIndexer();
    
    ~Wallet();
};


#endif /* Wallet_h */

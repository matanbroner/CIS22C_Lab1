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
    Currency* operator[](int i);
    
    void getCurrInfo();
    void getWalletInfo();
    void addCurrency(Currency*);
    void subtractCurrency(Currency*);
    void zeroOut();
    bool walletEmpty();
    void userManual();
    
    static int currencyIndexer();
    ~Wallet();
};


#endif /* Wallet_h */

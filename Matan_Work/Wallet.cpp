//
//  Wallet.cpp
//  CIS22C_Lab1
//
//  Created by Matan Broner on 9/29/18.
//  Copyright © 2018 Matan Broner. All rights reserved.
//

#include <stdio.h>
#include "Wallet.h"

using namespace std;

Wallet::Wallet()
{
    this->currArr[0] = new Dollar();
    this->currArr[1] = new Euro();
    this->currArr[2] = new Yen();
    this->currArr[3] = new Rupee();
    this->currArr[4] = new Yuan();
}

Currency* Wallet::operator[](int i)
{
    if( i > 4 ) {
        cout << "Index out of bounds" <<endl;
        // return first element.
        return currArr[0];
    }
    return currArr[i];
}

void Wallet::getCurrInfo()
{
    int index = currencyIndexer();
    cout << *this->currArr[index] << endl;
}

void Wallet::getWalletInfo()
{
    if (this->walletEmpty())
        cout << "Your wallet is completely empty!" << endl;
    else
    {
        cout << "<< Wallet status >>" << endl;
        for (int i = 0; i < NUMCURRS; i++)
        {
            cout << *this->currArr[i] << endl;
        }
    }
}

void Wallet::addCurrency(Currency* c)
{
    double valueAdd = 0;
    cout << "Amount of '" << c->getType() << "s' to ADD:" << endl;
    cout << "--> ";
    cin >> valueAdd;
    if (valueAdd >= 0)
    {
        valueAdd = Currency::round(valueAdd);
        *c += valueAdd;
        cout << valueAdd << " " << c->getType() << "s added to your wallet!" << endl;
    }
    else
        cout << "Cannot perform additions of negative values on currencies.\nUse 'subtract' feature." << endl;
}

void Wallet::subtractCurrency(Currency* c)
{
    double valueSub = 0;
    cout << "Amount of '" << c->getType() << "s' to SUBTRACT:" << endl;
    cout << "--> ";
    cin >> valueSub;
    if (valueSub >= 0)
    {
        if (valueSub <= c->getCurrValue())
        {
            valueSub = Currency::round(valueSub);
            *c -= valueSub;
            cout << valueSub << " " << c->getType() << "s subtracted from your wallet!" << endl;
        }
        else
        {
            cout << valueSub << " is more '" << c->getType() << "s' than you have!" << endl;
            cout << "Setting " << c->getType() << "s' to 0" << endl;
            c->setCurrency(0);
        }
    }
    else
        cout << "Cannot perform subtractions of negative values on currencies.\nUse 'add' feature." << endl;
}

void Wallet::zeroOut()
{
    for (int i = 0; i < 5; i++)
        this->currArr[i]->setCurrency(0);
    cout << "All " << NUMCURRS << " set to 0 value." << endl;
}

bool Wallet::walletEmpty()
{
    double total = 0;
    for (int i = 0; i < 5; i++)
        total+= this->currArr[i]->getCurrValue();
    if (total <= 0)
        return true;
    else return false;
}

int Wallet::currencyIndexer()
{
    int index = 0;
    cout << "Types of currencies available:" << endl;
    cout << "[1] -- Dollar" << endl;
    cout << "[2] -- Euro" << endl;
    cout << "[3] -- Yen" << endl;
    cout << "[4] -- Rupee" << endl;
    cout << "[5] -- Yuan" << endl;
    cout << "--> ";
    cin >> index;
    while (index < 1 || index > 5)
    {
        cout << "Out of bounds error, choose again." << endl;
        cout << "--> ";
        cin >> index;
    }
    return (index - 1);
}

void Wallet::userManual()
{
    cout << "<< Wallet User Manual >>\n" << endl;
    cout << "The wallet you are using is able to hold " << NUMCURRS << " types of currencies!" << endl;
    cout << "All currenices are based in increments of 1:100, meaning 100 small parts makes a whole currency value." << endl;
    cout << "Your wallet cannot hold negative values of currencies as a bank account would, any attempt to do so will leave the currency balance at hand with 0." << endl;
}

Wallet::~Wallet()
{
    for (int i = 0; i < 5; i++)
        delete this->currArr[i];
}




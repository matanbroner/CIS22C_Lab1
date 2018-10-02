//
//  Wallet.cpp
//  CIS22C_Lab1
//
//  Created by Matan Broner on 9/29/18.
//  Copyright © 2018 Matan Broner. All rights reserved.
//

#include <stdio.h>
#include <iomanip>
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
        cout << "<< Wallet status -- Showing currencies with non-zero values >>" << endl;
        for (int i = 0; i < NUMCURRS; i++)
        {
            if (this->currArr[i]->getCurrValue() > 0)
                cout << *this->currArr[i] << endl;
        }
    }
}

void Wallet::addCurrency(Currency* c)
{
    double valueAdd = 0;
    cout << "Amount of '" << c->getType() << "s' to ADD [ex. 12.56]:" << endl;
    cout << "--> ";
    try
    {
        cin >> valueAdd;
        if (cin.fail())
        {
            cin.clear();
            valueAdd = 0;
            throw "Error";
        }
    }
    catch(...)
    {
        cout << "Illegal value entered!" << endl;
    }
    if (valueAdd >= 0)
    {
        valueAdd = Currency::round(valueAdd);
        *c += valueAdd;
        cout << fixed << setprecision(2) << valueAdd << " " << c->getType() << "s added to your wallet!" << endl;
    }
    else
        cout << "Cannot perform additions of negative values on currencies.\nUse 'subtract' feature." << endl;
}

void Wallet::subtractCurrency(Currency* c)
{
    double valueSub = 0;
    cout << "Amount of '" << c->getType() << "s' to SUBTRACT [ex. 12.56]:" << endl;
    cout << "--> ";
    try
    {
        cin >> valueSub;
        if (cin.fail())
        {
            cin.clear();
            valueSub = 0;
            throw "Error";
        }
    }
    catch(...)
    {
        cout << "Illegal value entered!" << endl;
    }
    if (valueSub >= 0)
    {
        if (valueSub <= c->getCurrValue())
        {
            valueSub = Currency::round(valueSub);
            *c -= valueSub;
            cout << fixed << setprecision(2) << valueSub << " " << c->getType() << "s subtracted from your wallet!" << endl;
        }
        else
        {
            if (c->getCurrValue() > 0)
            {
                cout << valueSub << " is more '" << c->getType() << "s' than you have!" << endl;
                cout << "Setting " << c->getType() << "s' to 0" << endl;
                c->setCurrency(0);

            }
            else cout << "You have 0 " << c->getType() << ", cannot subtract." << endl;
        }
    }
    else
        cout << "Cannot perform subtractions of negative values on currencies.\nUse 'add' feature." << endl;
}

void Wallet::zeroOut()
{
    if (!this->walletEmpty())
    {
        cout << "Removing the following from your wallet: " << endl;
        for (int i = 0; i < 5; i++)
        {
            if (currArr[i]->getCurrValue() > 0)
                cout << currArr[i]->getType() << ": " << currArr[i]->getCurrValue() << endl;
            this->currArr[i]->setCurrency(0);
        }
        cout << "All " << NUMCURRS << " currencies have been set to 0 value." << endl;
    }
    else cout << "You have no currencies in your wallet, it is empty..." << endl;
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
    int index = -1;
    cout << "Types of currencies available:" << endl;
    cout << "[1] -- Dollar" << endl;
    cout << "[2] -- Euro" << endl;
    cout << "[3] -- Yen" << endl;
    cout << "[4] -- Rupee" << endl;
    cout << "[5] -- Yuan" << endl;
    do
    {
        cout << "--> ";
        try
        {
            cin >> index;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw "Illegal value given, choose again.\n";
            }
            if (index < 1 || index > 5)
            {
                throw "Out of bounds error, choose again.";
            }
        }
        catch (char const* error)
        {
            index = -1;
            cout << error;
        }
    } while (index == -1);
    return (index - 1);
}

void Wallet::userManual()
{
    cout << "\n<< Wallet User Manual >>\n" << endl;
    cout << "The wallet you are using is able to hold " << NUMCURRS << " types of currencies:\n\n{";
    for (int i = 0; i < NUMCURRS; i++)
    {
        if (i + 1 != NUMCURRS)
            cout << currArr[i]->getType() << ", ";
        else cout << currArr[i]->getType();
    }
    cout << "}\n\nAll currenices are based in increments of 1:100, meaning 100 small parts makes a whole currency value." << endl;
    cout << "Your wallet cannot hold negative values of currencies as a bank account would, any attempt to do so will leave the currency balance at hand with 0." << endl;
}

Wallet::~Wallet()
{
    for (int i = 0; i < 5; i++)
        delete this->currArr[i];
}




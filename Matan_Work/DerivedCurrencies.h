//
//  DerivedCurrencies.h
//  CIS22C_Lab1
//
//  Created by Matan Broner on 9/28/18.
//  Copyright © 2018 Matan Broner. All rights reserved.
//

#ifndef DerivedCurrencies_h
#define DerivedCurrencies_h
#include "Currency.h"

/*
 This file is a set of mostly identical classes that are all derived from the base Currency class
 They all have identically overloaded + and - operators to ensure that only objects of the same type can be added
 each other.
 */

class Dollar : public Currency
{
public:
    Dollar(double value); // Dollar object with value to be passed to base constructor
    Dollar();
    
    Dollar operator +(const Dollar& d); // overloaded + operator to add Dollar and Dollar
    Dollar operator -(const Dollar& d); // overloaded - operator to subtract Dollar and Dollar
    ~Dollar();
};

class Euro : public Currency
{
public:
    Euro(double value);
    Euro();
    
    Euro operator +(const Euro& d); // overloaded + operator to add Euro and Euro
    Euro operator -(const Euro& d); // overloaded - operator to subtract Eurp and Euro
    ~Euro();
};

class Yen : public Currency
{
public:
    Yen(double value);
    Yen();
    
    Yen operator +(const Yen& d); // overloaded + operator to add Yen and Yen
    Yen operator -(const Yen& d); // overloaded - operator to subtract Yen and Yen
    ~Yen();
};

class Rupee : public Currency
{
public:
    Rupee(double value);
    Rupee();
    
    Rupee operator +(const Rupee& d); // overloaded + operator to add Rupee and Rupee
    Rupee operator -(const Rupee& d); // overloaded - operator to subtract Rupee and Rupee
    ~Rupee();
};

class Yuan : public Currency
{
public:
    Yuan(double value);
    Yuan();
    
    Yuan operator +(const Yuan& d); // overloaded + operator to add Yuan and Yuan
    Yuan operator -(const Yuan& d); // overloaded - operator to subtract Yuan and Yuan
    ~Yuan();
};
#endif /* DerivedCurrencies_h */

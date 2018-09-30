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

class Dollar : public Currency
{
public:
    Dollar(double value);
    Dollar();
    
    Dollar operator +(const Dollar& d);
    Dollar operator -(const Dollar& d);
    
};

class Euro : public Currency
{
public:
    Euro(double value);
    Euro();
    
    Euro operator +(const Euro& d);
    Euro operator -(const Euro& d);
};

class Yen : public Currency
{
public:
    Yen(double value);
    Yen();
    
    Yen operator +(const Yen& d);
    Yen operator -(const Yen& d);
};

class Rupee : public Currency
{
public:
    Rupee(double value);
    Rupee();
    
    Rupee operator +(const Rupee& d);
    Rupee operator -(const Rupee& d);
};

class Yuan : public Currency
{
public:
    Yuan(double value);
    Yuan();
    
    Yuan operator +(const Yuan& d);
    Yuan operator -(const Yuan& d);
};
#endif /* DerivedCurrencies_h */

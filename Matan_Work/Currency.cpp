//
//  Currency.cpp
//  CIS22C_Lab1
//
//  Created by Matan Broner on 9/28/18.
//  Copyright © 2018 Matan Broner. All rights reserved.
//

#include <stdio.h>
#include <iomanip>
#include "Currency.h"

using namespace std;

Currency::Currency(string name, string f_name, double value) : c_name(name), c_fraction_name(f_name)
{
    setCurrency(round(value));
}

Currency::Currency(string name, string f_name): c_name(name), c_fraction_name(f_name), c_whole(0), c_fraction(0)
{}

void Currency::setCurrency(double value)
{
    int whole_place = value * 100; // removes 2 decimals aspect
    double dec_place = whole_place % 100; // modified value is then divided by 100 to get fractional amount
    whole_place /= 100; // returns two decimal places
    this->c_fraction = dec_place;
    this->c_whole = whole_place;
    normalizeCurrency(); // ensures that fractional is not past 100
}

void Currency:: operator +(){}
void Currency:: operator -(){}
void Currency:: operator+=(double value)
{
    this->setCurrency(this->getCurrValue() + value);
}

void Currency:: operator-=(double value)
{
    this->setCurrency(this->getCurrValue() - value);
}

void Currency::normalizeCurrency()
{
    while (this->c_fraction >= 100)
    {
        this->c_whole += 1;
        this->c_fraction -= 100;
    }
}

/*
 round(double val) takes val, multiplies it by 100, adds 0.5, and casts it to an int
 val is then returned as cast into double and divided by 100
 */
double Currency::round(double val)
{
    double value = (int)(val * 100 + .5);
    return (double)value / 100;
}

double Currency:: getCurrValue() const
{
    double dec = ((double)this->c_fraction)/100;
    return (this->c_whole + dec);
}

string Currency:: getType() const
{
    return this->c_name;
}

istream &operator>> (istream &input, Currency &c)
{
    double value = 0;
    cout << "Enter value: ";
    input >> value;
    c.setCurrency(value + c.getCurrValue());
    return input;
}

ostream& operator<< (ostream& output, const Currency &c)
{
    cout << "Currency Type: " << c.c_name << ", " << c.c_fraction_name << endl;
    cout << "Value: " << fixed << setprecision(2) << c.getCurrValue();
    return output;
}



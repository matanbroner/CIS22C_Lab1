//
//  Currency.cpp
//  CIS22C_Lab1
//
//  Created by Matan Broner on 9/28/18.
//  Copyright © 2018 Matan Broner. All rights reserved.
//

#include <stdio.h>
#include "Currency.h"

using namespace std;

Currency::Currency(string name, string f_name, double value) : c_name(name), c_fraction_name(f_name)
{
    setCurrency(value);
}

Currency::Currency(string name, string f_name): c_name(name), c_fraction_name(f_name), c_whole(0), c_fraction(0)
{}

void Currency::setCurrency(double value)
{
    int whole_place = value;
    this->c_whole = whole_place;
    double dec_place = (value - whole_place) * 100;
    this->c_fraction = dec_place;
    normalizeCurrency();
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

double Currency::round(double val)
{
    double value = (int)(val * 100 + .5);
    return (double)value / 100;
}

double Currency:: getCurrValue() const
{
    double dec = ((double)this->c_fraction)/100;
    return round(this->c_whole + dec);
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
    cout << "Value: " << c.getCurrValue();
    return output;
}



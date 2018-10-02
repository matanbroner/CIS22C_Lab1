//
//  Currency.h
//  CIS22C_Lab1
//
//  Created by Matan Broner on 9/27/18.
//  Copyright © 2018 Matan Broner. All rights reserved.
//

#ifndef Currency_h
#define Currency_h

#include <string>
#include <iostream>

class Currency
{
protected:
    std::string c_name;
    std::string c_fraction_name;
    int c_whole;
    int c_fraction;
    
public:
    
    Currency(std::string name, std::string f_name, double value);
    Currency(std::string name, std::string f_name);
    
    virtual void operator +();
    virtual void operator -();
    void operator +=(double val);
    void operator-=(double value);
    
    double getCurrValue() const;
    std::string getType() const;
    
    friend std::ostream& operator<< (std::ostream& output, const Currency &c);
    friend std::istream& operator>> (std::istream& input, Currency &c);
    
    static double round(double);
    void setCurrency(double value);
    void normalizeCurrency();
    
    virtual ~Currency(){};

};

#endif /* Currency_h */

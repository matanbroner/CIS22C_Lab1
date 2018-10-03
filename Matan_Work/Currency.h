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
    std::string c_name; // name of whole part of Currency (ex. Dollar)
    std::string c_fraction_name; // name of fractional part of Currency (ex. Cent)
    int c_whole; // amount of whole parts
    int c_fraction; // amount of fractional parts
    
public:
    
    Currency(std::string name, std::string f_name, double value); // Currency object with name and value given
    Currency(std::string name, std::string f_name); // Currency object with name given
    

    virtual void operator +(); // Used to add two Currency objects
    virtual void operator -(); // Used to subtract two Currency objects
    void operator +=(double val); // Used to add value to Currency object (divided among c_whole and c_fraction)
    void operator-=(double value); // Used to subtract value to Currency object (divided among c_whole and c_fraction)
    
    /* This method returns the current value stored in a Currency object in the form of a double
     Pre: none
     Post: none
     Return: Currency value in the form of a value
     */
    double getCurrValue() const;
    
    /* This method returns the "type" of a currency object, meaning its c_name value
     Pre: none
     Post: none
     Return: string value: Currency's c_name
     */
    std::string getType() const;
    
    friend std::ostream& operator<< (std::ostream& output, const Currency &c); // Used to output Currency object info
    friend std::istream& operator>> (std::istream& input, Currency &c); // Used to read value into new Currency object
    
    /* This algorithm rounds a double value to the nearest hundreths place
     Pre: double value
     Post: none
     Return: double value rounded to two decimal places
     */
    static double round(double);
    
    /* This method takes a double value and uses it to set Currency value's c_whole and c_fraction
     Pre: double value
     Post: this has c_whole and c_fraction attributes set
     Return: none
     */
    void setCurrency(double value);
    
    /* This algorithm ensures that the Currency object's c_fraction does not top 99, rolling into c_whole
     Pre: none
     Post: Currency's c_whole and c_fraction may have values modified
     Return: none
     */
    void normalizeCurrency();
    
    virtual ~Currency(){};

};

#endif /* Currency_h */

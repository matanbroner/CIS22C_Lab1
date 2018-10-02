//
//  DerivedCurrencies.cpp
//  CIS22C_Lab1
//
//  Created by Matan Broner on 9/29/18.
//  Copyright © 2018 Matan Broner. All rights reserved.
//

#include <stdio.h>
#include "DerivedCurrencies.h"

Dollar::Dollar(double value) : Currency("Dollar", "Cent", value)
{}

Dollar::Dollar(): Currency("Dollar", "Cent", 0)
{}

Dollar Dollar::operator+(const Dollar &d)
{
    Dollar temp;
    temp.setCurrency((this->getCurrValue() + d.getCurrValue()));
    return temp;
}

Dollar Dollar::operator-(const Dollar &d)
{
    Dollar temp;
    temp.setCurrency((this->getCurrValue() - d.getCurrValue()));
    
    return temp;
}

Dollar::~Dollar(){}

Euro::Euro(double value) : Currency("Euro", "Cent", value)
{}

Euro::Euro(): Currency("Euro", "Cent", 0)
{}

Euro Euro::operator+(const Euro &d)
{
    Euro temp;
    temp.setCurrency((this->getCurrValue() + d.getCurrValue()));
    
    return temp;
}

Euro Euro::operator-(const Euro &d)
{
    Euro temp;
    temp.setCurrency((this->getCurrValue() - d.getCurrValue()));
    
    return temp;
}

Euro::~Euro(){}


Yen::Yen(double value) : Currency("Yen", "Sen", value)
{}

Yen::Yen(): Currency("Yen", "Sen", 0)
{}

Yen Yen::operator+(const Yen &d)
{
    Yen temp;
    temp.setCurrency((this->getCurrValue() + d.getCurrValue()));
    
    return temp;
}

Yen Yen::operator-(const Yen &d)
{
    Yen temp;
    temp.setCurrency((this->getCurrValue() - d.getCurrValue()));
    
    return temp;
}

Yen::~Yen(){}


Rupee::Rupee(double value) : Currency("Rupee", "Paise", value)
{}

Rupee::Rupee(): Currency("Rupee", "Paise", 0)
{}

Rupee Rupee::operator+(const Rupee &d)
{
    Rupee temp;
    temp.setCurrency((this->getCurrValue() + d.getCurrValue()));
    
    return temp;
}

Rupee Rupee::operator-(const Rupee &d)
{
    Rupee temp;
    temp.setCurrency((this->getCurrValue() - d.getCurrValue()));
    
    return temp;
}

Rupee::~Rupee(){}


Yuan::Yuan(double value) : Currency("Yuan", "Fen", value)
{}

Yuan::Yuan(): Currency("Yuan", "Fen", 0)
{}

Yuan Yuan::operator+(const Yuan &d)
{
    Yuan temp;
    temp.setCurrency((this->getCurrValue() + d.getCurrValue()));
    
    return temp;
}

Yuan Yuan::operator-(const Yuan &d)
{
    Yuan temp;
    temp.setCurrency((this->getCurrValue() - d.getCurrValue()));
    
    return temp;
}

Yuan::~Yuan(){}




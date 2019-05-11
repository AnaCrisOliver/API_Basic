//
// Created by ana on 10/05/19.
//

#include "System.h"


System::System(double value)
{
    this->conservative_value = value;

}

double System::getConservativeValue(){
    return conservative_value;
}

void System::setConservativeValue(double conservativeValue)
{
    conservative_value = conservativeValue;
}

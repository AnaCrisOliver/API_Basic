//
// Created by ana on 10/05/19.
//

#ifndef API_SYSTEM_SYSTEM_H
#define API_SYSTEM_SYSTEM_H

#include <iostream>

using namespace std;

class System {
private:
    double conservative_value;
public:
    double getConservativeValue();

    void setConservativeValue(double conservativeValue);

    System(){};
    System(double value);
    ~System(){};
    //o construtor tem que ter essa chave, senao da referencia indefinida

};


#endif //API_SYSTEM_SYSTEM_H

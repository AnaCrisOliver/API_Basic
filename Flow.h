//
// Created by ana on 10/05/19.
//

#ifndef API_SYSTEM_FLOW_H
#define API_SYSTEM_FLOW_H

#include <cmath>
#include "System.h"

class Flow {
private:
    System* source;
    System* terminal;
    char function;
public:

    Flow(){}

    Flow(System* s, System* t);
    Flow(System* s, System* t, char f);

    ~Flow(){}

    System* get_Source();

    System* get_Terminal();

    char get_Function() const;

    void set_Function(char function);

    void set_Source(System source);

    void set_Terminal(System terminal);

    void set_terminal_value(double v);

    double calculate();

    double calculate(int exp);

};


#endif //API_SYSTEM_FLOW_H

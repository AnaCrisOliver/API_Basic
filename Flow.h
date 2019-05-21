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
    double energy;
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

    void set_source_value(double v);

    double get_terminal_value();

    double get_source_value();

    double calculate();

    double calculate(int exp);

    void set_energy(double v);

    double get_energy();

};


#endif //API_SYSTEM_FLOW_H

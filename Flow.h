//
// Created by ana on 10/05/19.
//

#ifndef API_SYSTEM_FLOW_H
#define API_SYSTEM_FLOW_H

#include "System.h"

class Flow {
private:
    System* source;
    System* terminal;
public:
    System* get_Source();

    System* get_Terminal();

    void set_Source(System source);

    void set_Terminal(System terminal);

    void set_terminal_value(double v);

    double calculate();

    Flow(){}

    Flow(System* s, System* t);

    ~Flow(){}

};


#endif //API_SYSTEM_FLOW_H

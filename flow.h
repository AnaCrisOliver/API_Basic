#ifndef FLOW_H
#define FLOW_H

//
// Created by ana on 10/05/19.
//

#include <cmath>
#include "systemimpl.h"
#include "system.h"

class Flow {

public:

    virtual void set_energy(double) = 0;

    virtual double get_energy() = 0;

    virtual char get_Function() const = 0;

    virtual void set_Function(char) = 0;

    virtual void set_Source() = 0;

    virtual void set_Terminal() = 0;

   // virtual System get_Source() = 0;

   // virtual System get_Terminal() = 0;

    virtual void set_terminal_energy(double) = 0;

    virtual void set_source_energy(double) = 0;

    virtual double get_terminal_energy() = 0;

    virtual double get_source_energy() = 0;

    virtual double calculate() = 0;


};

#endif // FLOW_H

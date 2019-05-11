//
// Created by ana on 10/05/19.
//

#include "Flow.h"

Flow:: Flow(System* s, System* t)
{
    source = s;
    terminal = t;
}
System* Flow::get_Source() {
    return source;
}

void Flow::set_Source(System source) {
    this->source = &source;
}

System* Flow::get_Terminal() {
    return terminal;
}

void Flow::set_Terminal(System terminal) {
    this->terminal = &terminal;
}

void Flow::set_terminal_value(double v)
{
    terminal->setConservativeValue(v);
}

double Flow::calculate()
{
    return source->getConservativeValue() * 0.3;
}

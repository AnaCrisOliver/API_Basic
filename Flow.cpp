//
// Created by ana on 10/05/19.
//

#include "Flow.h"

Flow:: Flow(System* s, System* t)
{
    source = s;
    terminal = t;
}


Flow:: Flow(System* s, System* t, char f)
{
    source = s;
    terminal = t;
    function = f;
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

//Calculates exponential
double Flow::calculate(int exp)
{
    return pow(source->getConservativeValue(),2);
}

double Flow::calculate()
{
    switch (Flow::function){
        case 'f':
            //Calculate natural logarithm
            return log(source->getConservativeValue());
        case 'g':
            //Calculate Population Grow
            return source->getConservativeValue()* 0.3;

        case 'r':
            return source->getConservativeValue() + 4.0;

        case 't':
            return source->getConservativeValue() + 3.33;
        case 'u':
            return pow(source->getConservativeValue(),3);
        case 'v':
            return source->getConservativeValue() - 3;
        case 'e':
            return pow(source->getConservativeValue(),2);

        case 'l': //logistic function
            return pow(source->getConservativeValue(),2);


    }
}

char Flow::get_Function() const {
    return function;
}

void Flow::set_Function(char f) {
    Flow::function = f;
}

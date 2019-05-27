#include "flowimpl.h"

FlowImpl::FlowImpl()
{

}

FlowImpl::FlowImpl(SystemImpl* s, SystemImpl* t,char f,double e)
{
    source = s;
    terminal = t;
    function = f;
    energy = e;
}

FlowImpl& FlowImpl:: operator=(FlowImpl& f)
{
    if(&f == this) return *this;
    source = f.get_Source();
    terminal = f.get_Terminal();
    function = f.get_Function();
    energy = f.get_energy();
    return *this;
}
void FlowImpl::set_energy(double e)
{
    energy = e;
}

double FlowImpl::get_energy()
{
    return energy;
}

char FlowImpl::get_Function() const
{
    return function;
}

void FlowImpl::set_Function(char f)
{
    function = f;
}

void FlowImpl::set_Source(SystemImpl* s)
{
    source = s;
}

void FlowImpl::set_Terminal(SystemImpl* t)
{
    terminal = t;
}

SystemImpl* FlowImpl::get_Source()
{
    return source;
}

SystemImpl* FlowImpl::get_Terminal()
{
    return terminal;
}

void FlowImpl::set_terminal_energy(double e)
{
    terminal->set_energy(e);
}

void FlowImpl::set_source_energy(double e)
{
    source->set_energy(e);
}

double FlowImpl::get_terminal_energy()
{
    return terminal->get_energy();
}

double FlowImpl::get_source_energy()
{
    return source->get_energy();
}

double FlowImpl::calculate()
{
    switch (function){

        case 'x':
            //exponencial function
            return source->get_energy() * 0.01;
        case 'l':
        //logistic function
            return (0.01 * terminal->get_energy()) * (1- (terminal->get_energy()/70));
    }
}

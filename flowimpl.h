#ifndef FLOWIMPL_H
#define FLOWIMPL_H
#include "flow.h"
#include "systemimpl.h"

class FlowImpl : public Flow
{
protected:

    double energy;
    SystemImpl* source;
    SystemImpl* terminal;
    char function;

public:

    FlowImpl& operator=(FlowImpl&);

    FlowImpl();

    FlowImpl(SystemImpl*, SystemImpl*,char,double);

    ~FlowImpl(){}

    void set_energy(double);

    double get_energy();

    char get_Function() const;

    void set_Function(char);

    void set_Source(SystemImpl*);

    void set_Terminal(SystemImpl*);

    void set_Source(){}

    void set_Terminal(){}

    SystemImpl* get_Source();

    SystemImpl* get_Terminal();

    void set_terminal_energy(double);

    void set_source_energy(double);

    double get_terminal_energy();

    double get_source_energy();

    double calculate();

};

#endif // FLOWIMPL_H

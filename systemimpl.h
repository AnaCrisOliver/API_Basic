#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H
#include "system.h"

class SystemImpl : public System
{
protected:

    double energy;

public:
    SystemImpl();

    SystemImpl(double);

    System* operator=(System& s);

    void set_energy(double eg);

    double get_energy();
    
    ~SystemImpl(){}
};

#endif // SYSTEMIMPL_H

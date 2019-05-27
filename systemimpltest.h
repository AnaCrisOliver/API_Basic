#ifndef SYSTEMIMPLTEST_H
#define SYSTEMIMPLTEST_H
#include "systemimpl.h"
#include <iostream>
#include <assert.h>
using namespace std;

class SystemImplTest : public SystemImpl
{
public:
    SystemImplTest();
    void unit_get_energy();
    void unit_set_energy();
    void unit_constructor();
};

#endif // SYSTEMIMPLTEST_H

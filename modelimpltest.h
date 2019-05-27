#ifndef MODELIMPLTEST_H
#define MODELIMPLTEST_H

#include "modelimpl.h"
#include <iostream>
#include <assert.h>

using namespace std;

class ModelImplTest : public ModelImpl
{
public:
    ModelImplTest();
    void unit_add_flow();
    void unit_remove_flow();
    void unit_add_system();
    void unit_remove_system();
};

#endif // MODELIMPLTEST_H

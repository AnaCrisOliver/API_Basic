#include "systemimpltest.h"

SystemImplTest::SystemImplTest(){}

//Testing System methods
void SystemImplTest::unit_get_energy()
{
    energy = 100.000;
    assert((get_energy() - 99.000) < 1.001);
}

void SystemImplTest::unit_set_energy()
{
    set_energy(100.000);
    assert((energy - 99.000) < 1.001);
}

void SystemImplTest::unit_constructor()
{
    SystemImpl s1(100.000);
    assert((s1.get_energy() - 99.000) < 1.001);
}


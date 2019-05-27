#include <iostream>
#include "system.h"
#include "systemimpl.h"
#include "modelimpl.h"
#include "flowimpl.h"
#include "systemimpltest.h"
#include "modelimpltest.h"

using namespace std;

int main()
{
    SystemImplTest test1;
    ModelImplTest test2;
    System *s = new SystemImpl();
    test1.unit_set_energy();
    test1.unit_get_energy();
    test1.unit_constructor();
    test2.unit_add_flow();
    test2.unit_add_system();
    test2.unit_remove_flow();
    test2.unit_remove_system();
    cout << "Hello World!" << endl;
    return 0;
}

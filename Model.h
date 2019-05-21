//
// Created by ana on 10/05/19.
//

#ifndef API_SYSTEM_MODEL_H
#define API_SYSTEM_MODEL_H

#include <iostream>
#include <list>
#include <assert.h>
#include "System.h"
#include "Flow.h"
#include <iterator>

using namespace std;

class Model {

private:
 /*   typedef list<System> System_List;
    System_List systems;
    typedef list<Flow> Flow_List;
    Flow_List flows;*/
    list<System*> systems;
    list<System*>::iterator it_system;

    list<Flow*> flows;
    list<Flow*>::iterator it_flow;

public:
 //   typedef System_List :: iterator it_flow;
   // it_flow it_flows;

    void add(System* s);
    void add(Flow* f);
    void print();
    void run();
    void run(int inicial, int final);
    void run(Flow* f);
    void remove(System s);
    void test1();
    void test2();
    void test3();
    Model(){}
    ~Model(){}

};


#endif //API_SYSTEM_MODEL_H

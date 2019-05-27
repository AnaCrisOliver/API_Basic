#ifndef MODELIMPL_H
#define MODELIMPL_H
#include <iostream>
#include <list>
#include <iterator>
#include "model.h"
#include "systemimpl.h"
#include "flowimpl.h"

using namespace std;

class ModelImpl : public Model
{
protected:
    list<SystemImpl*> systems;
    list<SystemImpl*>::iterator it_system;

    list<FlowImpl*> flows;
    list<FlowImpl*>::iterator it_flow;
public:
    ModelImpl();
    ModelImpl(ModelImpl*)
    
    ModelImpl& operator=(ModelImpl*);
    void add(SystemImpl*);
    void add(FlowImpl* f);
    void add(){}
    void print();
    void run(int inicial, int final);
    void remove(){}
    void remove(SystemImpl*);
    void remove(FlowImpl* f);
    bool search(){}
    bool search(SystemImpl*);
    bool search(FlowImpl* f);
    ~ModelImpl(){}
};

#endif // MODELIMPL_H

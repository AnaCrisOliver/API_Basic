#ifndef MODEL_H
#define MODEL_H
#include "system.h"
#include "flow.h"

class Model{
public:
    virtual void add(System* s)=0;
    virtual void add(Flow* f)=0;
    virtual void print()=0;
    virtual void run(int inicial, int final)=0;
    virtual void remove(System* s)=0;
    virtual void remove(Flow* f)=0;
    virtual bool search(System* s)=0;
    virtual bool search(Flow* f)=0;

    virtual vector<System*>::iterator systemBegin() = 0;
    virtual vector<System*>::iterator systemEnd() = 0;

    virtual vector<Flow*>::iterator flowBegin() = 0;
    virtual vector<Flow*>::iterator flowEnd() = 0;
    
    virtual ~Model(){};
};

#endif // MODEL_H

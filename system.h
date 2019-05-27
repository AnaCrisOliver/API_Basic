#ifndef SYSTEM_H
#define SYSTEM_H
class System{
public:
    virtual ~System(){};

    virtual System* operator=(System* s) = 0;

    virtual ~System(){}
};

#endif // SYSTEM_H

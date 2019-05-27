#include "modelimpltest.h"

ModelImplTest::ModelImplTest()
{}
void ModelImplTest::unit_add_flow()
{

    SystemImpl s1(100),s2(0);
    FlowImpl f1(&s1,&s2,'x',100),f2(&s1,&s2,'x',100),f3(&s1,&s2,'x',100),
            f4(&s1,&s2,'x',100),f5(&s1,&s2,'x',100),f6(&s1,&s2,'x',100);
    add(&f1);
    add(&f2);
    add(&f3);
    add(&f4);
    add(&f5);
    add(&f6);

    assert(search(&f1) == true);
    assert(search(&f2) == true);
    assert(search(&f3) == true);
    assert(search(&f4) == true);
    assert(search(&f5) == true);
    assert(search(&f5) == true);
}

void ModelImplTest::unit_add_system()
{

    list<System*>::iterator it_system;
    SystemImpl s1(100),s2(100),s3(100),s4(100),s5(100);
    add(&s1);
    add(&s2);
    add(&s3);
    add(&s4);
    add(&s5);

    assert(search(&s1) == true);
    assert(search(&s2) == true);
    assert(search(&s3) == true);
    assert(search(&s4) == true);
    assert(search(&s5) == true);
}

void ModelImplTest::unit_remove_system()
{
    SystemImpl s1(100),s2(100);
    add(&s1);
    add(&s2);
    remove(&s1);
    remove(&s2);
    assert(search(&s1) == false);
    assert(search(&s2) == false);

}

void ModelImplTest::unit_remove_flow()
{

    SystemImpl s1(100.000),s2(100.000);
    FlowImpl f1(&s1,&s2,'x',100.000),f2(&s1,&s2,'x',100.000);
    add(&f1);
    add(&f2);
    remove(&f1);
    remove(&f2);
    assert(search(&f1) == false);
    assert(search(&f2) == false);

}

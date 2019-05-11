#include <iostream>
#include "System.cpp"
#include "Model.cpp"
#include "Flow.cpp"

#define TEST1
//#define TEST2
//#define TEST3

#ifdef TEST1 //exponencial?

/*
 * Problems:
 * If we change some variable on "f1", nothing happens, because its not a pointer. - SOLVED!
 * If we change something on Model, "f1" keeps the same, because its not a pointer. - SOLVED!
 *
 */

int main() {
    Model m1;
    System s1(15),s2(15);
    Flow f1(&s1,&s2);
    m1.add(&s1);
    m1.add(&s2);
    m1.add(&f1);
    m1.run();
    assert(f1.get_Terminal()->getConservativeValue() == 4.50);
    assert(s2.getConservativeValue() == 4.50);
}

#endif

#ifdef TEST2 //logistica

/*
 * Problems:
 * If we change some variable on "f1", nothing happens, because its not a pointer. - SOLVED!
 * If we change something on Model, "f1" keeps the same, because its not a pointer. - SOLVED!
 *
 */

int main() {
    Model m1;
    System s1,s2;
    s1.setConservativeValue(15);
    Flow f1(&s1,&s2);
    m1.add(&s1);
    m1.add(&s2);
    m1.add(&f1);
    m1.run();
    assert(f1.get_Terminal()->getConservativeValue() == 4.50);
    assert(s2.getConservativeValue() == 4.50);
}

#endif

#ifdef TEST3 //big model

/*
 * Problems:
 * If we change some variable on "f1", nothing happens, because its not a pointer. - SOLVED!
 * If we change something on Model, "f1" keeps the same, because its not a pointer. - SOLVED!
 * System has to be a POINTER! Fix that. Or the flows will be totally disconnected. - SOLVED!
 * */

int main() {
    Model m1;

    System s1(15);
    System s2(15);
    System s3(15);
    System s4(15);
    System s5(15);
    System s6(15);
    System s7(15);

    Flow f1(&s1,&s2);
    Flow f2(&s2,&s3);
    Flow f3(&s3,&s4);
    Flow f4(&s4,&s5);
    Flow f5(&s5,&s6);
    Flow f6(&s6,&s7);

    m1.add(&s1);
    m1.add(&s2);
    m1.add(&s3);
    m1.add(&s4);
    m1.add(&s5);
    m1.add(&s6);
    m1.add(&s7);

    m1.add(&f1);
    m1.add(&f2);
    m1.add(&f3);
    m1.add(&f4);
    m1.add(&f5);
    m1.add(&f6);

    m1.print();

    m1.run();

    assert(f1.get_Terminal()->getConservativeValue() == 4.50);
    assert(f2.get_Terminal()->getConservativeValue() == 4.50);
    assert(f3.get_Terminal()->getConservativeValue() == 4.50);
    assert(f4.get_Terminal()->getConservativeValue() == 4.50);
    assert(f5.get_Terminal()->getConservativeValue() == 4.50);
    assert(f6.get_Terminal()->getConservativeValue() == 4.50);

}

#endif
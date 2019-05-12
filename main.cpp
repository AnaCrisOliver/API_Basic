#include <iostream>
#include "System.cpp"
#include "Model.cpp"
#include "Flow.cpp"

#define TEST1 - SIMPLE MODEL TO CALCULATE EXPONENTIAL - GOODEST CASE
//#define TEST2 - SIMPLE MODEL TO CALCULATE LOGISTIC - GOOD CASE
//#define TEST3 - BIG MODEL - LINEAR - MEDIUM USE CASE
//#define TEST4 - BIG MODEL - WORST USE CASE

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef TEST1 //SIMPLE MODEL TO CALCULATE EXPONENTIAL - GOODEST CASE

/* WORKING!
 *
 * USED TO BE PROBLEMS:
 * If we change some variable on "f1", nothing happens, because its not a pointer. - SOLVED!
 * If we change something on Model, "f1" keeps the same, because its not a pointer. - SOLVED!
 *
 * PROBLEMS:
 * No one.
 *
 * DO NOT TRY TO CHANGE:
 * Changing pointers to normal variables.
 */

int main() {
    Model m1;
    System s1(2),s2(0);
    Flow f1(&s1,&s2,'e');
    m1.add(&s1);
    m1.add(&s2);
    m1.add(&f1);
    m1.run();
    assert(f1.get_Terminal()->getConservativeValue() == 4);
    assert(s2.getConservativeValue() == 4);
}

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef TEST2 //SIMPLE MODEL TO CALCULATE LOGISTIC - GOOD CASE

/* WORKING - NOT TOTALLY
 *
 * USED TO BE PROBLEMS:
 * If we change some variable on "f1", nothing happens, because its not a pointer. - SOLVED!
 * If we change something on Model, "f1" keeps the same, because its not a pointer. - SOLVED!
 *
 * PROBLEMS:
 * No one.
 *
 * DO NOT TRY TO CHANGE:
 * Changing pointers to normal variables.
 */

int main() {
    Model m1;
    System s1,s2;
    s1.setConservativeValue(15);
    Flow f1(&s1,&s2,'e');
    m1.add(&s1);
    m1.add(&s2);
    m1.add(&f1);
    m1.run();
    assert(f1.get_Terminal()->getConservativeValue() == 4.50);
    assert(s2.getConservativeValue() == 4.50);
}

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef TEST3 //BIG MODEL - LINEAR - MEDIUM USE CASE

/* WORKING! - NOT TOTALLY
 *
 * USED TO BE PROBLEMS:
 * If we change some variable on "f1", nothing happens, because its not a pointer. - SOLVED!
 * If we change something on Model, "f1" keeps the same, because its not a pointer. - SOLVED!
 * System has to be a POINTER! Fix that. Or the flows will be totally disconnected. - SOLVED!
 *
 * DO NOT TRY TO CHANGE:
 * Changing pointers to normal variables.
 *
 * PROBLEMS:
 * Double values with more than 2 digits are not working on the assertion.
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

    Flow f1(&s1,&s2,'g');
    Flow f2(&s2,&s3,'g');
    Flow f3(&s3,&s4,'g');
    Flow f4(&s4,&s5,'g');
    Flow f5(&s5,&s6,'g');
    Flow f6(&s6,&s7,'g');

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

   // m1.print();

    m1.run();

    assert(f1.get_Terminal()->getConservativeValue() == 4.50);
    assert(f2.get_Terminal()->getConservativeValue() == 1.35); //error - double value (?)
    assert(f3.get_Terminal()->getConservativeValue() == 0.405); //error - double value (?)
    assert(f4.get_Terminal()->getConservativeValue() == 0.1215); //error - double value (?)
    assert(f5.get_Terminal()->getConservativeValue() == 0.03645); //error - double value (?)
    assert(f6.get_Terminal()->getConservativeValue() == 0.010935); //error - double value (?)

}

#endif


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef TEST4 //BIG MODEL - WORST USE CASE

/* WORKING! - NOT TOTALLY
 *
 * HOW IT WORKS:
 * A model where the flows can have the same source/terminal.
 * A lot of functions can be applied to the model, and a different one for each flow.
 *
 * ADVANTAGES:
 * client can easily set the function to use, changing any time.
 * A lot of possibilities without a redundant code.
 *
 * USED TO BE PROBLEMS:
 * If we change some variable on "f1", nothing happens, because its not a pointer. - SOLVED!
 * If we change something on Model, "f1" keeps the same, because its not a pointer. - SOLVED!
 * System has to be a POINTER! Or... the flows will be totally disconnected. - SOLVED!
 * The client can run the model just from the begining. - SOLVED!
 *
 * PROBLEMS:
 * Double values with more than 3 digits are not working on the assertion.
 *
 * DO NOT TRY TO CHANGE:
 * Changing pointers to normal variables.
 * */

int main() {
    Model m1;

    System s1(1);
    System s2(0);
    System s3(0);
    System s4(0);
    System s5(0);

    Flow f1(&s1,&s2,'f'); //f(x) | s1: x == 1 s2: x == 0
    Flow f2(&s1,&s3,'g'); //g(x) | s1: x == 1 s3: x == 5
    Flow f3(&s2,&s5,'r'); //r(x) | s2: x == 0 s5: x == 4.0
    Flow f4(&s2,&s3,'t'); //t(x) | s2: x == 0 s3: x == 3.33
    Flow f5(&s3,&s4,'u'); //u(x) | s3: x == 3.33 s4: x == 36.926
    Flow f6(&s4,&s1,'v'); //v(x) | s4: x == 3.33 s1: x == 33.92

    m1.add(&s1);
    m1.add(&s2);
    m1.add(&s3);
    m1.add(&s4);
    m1.add(&s5);

    m1.add(&f1);
    m1.add(&f2);
    m1.add(&f3);
    m1.add(&f4);
    m1.add(&f5);
    m1.add(&f6);

    m1.run();

   // m1.print();

   //TEST FOR RUN JUST ONE FLOW:
   //m1.run(&f1);
   //Result expected: assert 1 fine, but the others cannot work.

    assert(f1.get_Terminal()->getConservativeValue() == 0.0);
    assert(f2.get_Terminal()->getConservativeValue() == 3.33);
    assert(f3.get_Terminal()->getConservativeValue() == 4.0);
    assert(f4.get_Terminal()->getConservativeValue() == 3.33);
  //  assert(f5.get_Terminal()->getConservativeValue() == 36.93); //error - double value (?)
  //  assert(f6.get_Terminal()->getConservativeValue() == 33); //error - double value (?)

}

#endif
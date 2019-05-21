#include <iostream>
#include <cmath>
#include "System.cpp"
#include "Model.cpp"
#include "Flow.cpp"

//TEST1 - SIMPLE MODEL TO CALCULATE EXPONENTIAL
//TEST2 - SIMPLE MODEL TO CALCULATE LOGISTIC
//TEST3 - BIG MODEL WITH EXPONENTIAL

int main() {
    Model m1,m2,m3;
    m1.test1();
    m2.test2();
    m3.test3();
    cout<<"TESTED WITH SUCESS"<<endl;
}


//
// Created by ana on 10/05/19.
//

#include "Model.h"

void Model::add(System* s)
{
    systems.push_back(s);
}

void Model::add(Flow* f)
{
    flows.push_back(f);
}

void Model::print()
{
        cout<<"\n---PRINTING SYSTEMS---"<<endl;
        for ( it_system = systems.begin();it_system!= systems.end(); it_system++ )
        {
            cout<<"\nSYSTEM value: "<<(*it_system)->getConservativeValue();
        }
        cout<<"\n---PRINTING FLOWS---"<<endl;
        for ( it_flow = flows.begin(); it_flow != flows.end(); it_flow++ )
        {

            cout<<"\nFLOW value: "<<(*it_flow)->get_Terminal()->getConservativeValue();
        }
}

void Model::run()
{
    double result[flows.size()];
    double source_aux[flows.size()];
    double terminal_aux[flows.size()];

    int i=0;
    for ( it_flow = flows.begin(); it_flow != flows.end(); it_flow++ )
    {
        result[i] = (*it_flow)->calculate();
        i++;
    }

    i=0;

    for ( it_flow = flows.begin(); it_flow != flows.end(); it_flow++ )
    {
        (*it_flow)->set_source_value(((*it_flow)->get_source_value() - result[i]));
        (*it_flow)->set_terminal_value(((*it_flow)->get_terminal_value() + result[i]));
        //(*it_flow)->set_source_value(((*it_flow)->get_source_value()) - result[i]);
        //(*it_flow)->set_terminal_value(((*it_flow)->get_terminal_value()) + result[i]);
        i++;
    }
        

}

void Model::run(int inicio, int fim)
{
    double result[flows.size()];
    double source_aux[flows.size()];
    double terminal_aux[flows.size()];

    int i=0;

    for(int j = inicio; j < fim; j++)
    {
        i=0;

        for ( it_flow = flows.begin(); it_flow != flows.end(); it_flow++ )
        {
            (*it_flow)->set_energy((*it_flow)->calculate());
            //result[i] = (*it_flow)->calculate();
            i++;
        }

        i=0;

        for ( it_flow = flows.begin(); it_flow != flows.end(); it_flow++ )
        {
            (*it_flow)->set_source_value((*it_flow)->get_source_value() - (*it_flow)->get_energy());
            (*it_flow)->set_terminal_value((*it_flow)->get_terminal_value() + (*it_flow)->get_energy());

           // (*it_flow)->set_source_value(((*it_flow)->get_source_value() - result[i]));
           // (*it_flow)->set_terminal_value(((*it_flow)->get_terminal_value() + result[i]));

            i++;
        }
    }

}

void Model::run(Flow* f)
{
    double result = 0.0;

    for ( it_flow = flows.begin(); it_flow != flows.end(); it_flow++ )
    {
        if(*it_flow == f)
        {
            result = (*it_flow)->calculate();
            (*it_flow)->set_terminal_value(result);
        }

    }
}

void Model::remove(System s)
{
    for ( it_flow = flows.begin(); it_flow != flows.end(); it_flow ++ )
    {

    }
}

void Model::test1()
{
    Model m1;
    System s1(100),s2(0);
    Flow f1(&s1,&s2,'x');
    m1.add(&s1);
    m1.add(&s2);
    m1.add(&f1);
    m1.run(0,100);

   // assert(fabs(s1.getConservativeValue() - 36.6032) < 0.0001);

    assert(fabs(s1.getConservativeValue() - 36.6032) < 0.0001);
    assert(fabs(s2.getConservativeValue() - 63.3968) < 0.0001);
}

void Model::test2()
{
    Model m1;
    System s1(100),s2(10);
    Flow f1(&s1,&s2,'l');
    m1.add(&s1);
    m1.add(&s2);
    m1.add(&f1);
    m1.run(0,100);

    assert(fabs(s1.getConservativeValue() - 88.2167) < 0.0001);
    assert(fabs(s2.getConservativeValue() - 21.7833) < 0.0001);
}

void Model::test3()
{
    Model m1;

    System s1(100);
    System s2(0);
    System s3(100);
    System s4(0);
    System s5(0);

    Flow f1(&s1,&s2,'x'); //f(x) | s1: x == 1 s2: x == 0
    Flow f2(&s1,&s3,'x'); //g(x) | s1: x == 1 s3: x == 5
    Flow f3(&s2,&s5,'x'); //r(x) | s2: x == 0 s5: x == 4.0
    Flow f4(&s2,&s3,'x'); //t(x) | s2: x == 0 s3: x == 3.33
    Flow f5(&s3,&s4,'x'); //u(x) | s3: x == 3.33 s4: x == 36.926
    Flow f6(&s4,&s1,'x'); //v(x) | s4: x == 3.33 s1: x == 33.92

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

    m1.run(0,100);

    //m1.print();

    //cout<< "s1: "<<fixed<< s1.getConservativeValue()<<endl;

    //cout<< "s1: "<<fixed<< s1.getConservativeValue() - 31.8513 <<endl;

    //cout<< "s2: "<<fixed<< s2.getConservativeValue()<<endl;

    //cout<< "s3: "<<fixed<< s3.getConservativeValue()<<endl;

    //cout<< "s4: "<<fixed<< s4.getConservativeValue()<<endl;

    //cout<< "s5: "<<fixed<< s5.getConservativeValue()<<endl;

    cout.flush();
    assert(fabs(s1.getConservativeValue() - 31.8513) < 0.0001);
    assert(fabs((s2.getConservativeValue()) - 18.4003) < 0.0001);
    assert(fabs(s3.getConservativeValue() - 77.1143) < 0.0001);
    assert(fabs(s4.getConservativeValue() - 56.1728) < 0.0001);
    assert(fabs(s5.getConservativeValue() - 16.4612) < 0.0001);

    // assert((s1.getConservativeValue()) - 31.8513 < 0.0001);
   //  assert((s2.getConservativeValue()) - 18.4003 < 0.0001);
   //TEST FOR RUN JUST ONE FLOW:
   //m1.run(&f1);
}


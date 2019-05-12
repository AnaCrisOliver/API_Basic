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
    double result = 0.0;

    for ( it_flow = flows.begin(); it_flow != flows.end(); it_flow++ )
    {
        result = (*it_flow)->calculate();
       // cout<<"\nFunction: "<< (*it_flow)->get_Function()<<endl;
       // cout<<"\nresult: "<< result;
        (*it_flow)->set_terminal_value(result);
       // assert((*it_flow)->get_Terminal()->getConservativeValue() == 4.5);
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
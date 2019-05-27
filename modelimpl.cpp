#include "modelimpl.h"

ModelImpl::ModelImpl()
{}
ModelImpl& ModelImpl:: operator=(ModelImpl* f)
{
    FlowImpl* aux = new FlowImpl();
    SystemImpl* aux2 = new SystemImpl();
    if(f == this) return *this;
    list<FlowImpl*>::iterator it_flow2;
    it_flow2 = f->flows.begin();
    for(it_flow = f->flows.begin(); it_flow != f->flows.end(); it_flow++)
    {
        if(it_flow2 != f->flows.end())
        {
            aux = (*it_flow2);
            this->add(aux);
            it_flow2++;
        }
    }
    list<SystemImpl*>::iterator it_system2;
    for(it_system = f->systems.begin(); it_system != f->systems.end(); it_system++)
    {
        if(it_system != f->systems.end())
        {
            aux2 = (*it_system2);
            this->add(aux2);
            it_system2++;
        }
    }

    return *this;
}
void ModelImpl::add(SystemImpl* s)
{
    systems.push_back(s);
}
void ModelImpl::add(FlowImpl* f)
{
    flows.push_back(f);
}
void ModelImpl::print()
{
    cout<<"\n---PRINTING SYSTEMS---"<<endl;
    for ( it_system = systems.begin();it_system!= systems.end(); it_system++ )
    {
        cout<<"\nSYSTEM value: "<<(*it_system)->get_energy();
    }
    cout<<"\n---PRINTING FLOWS---"<<endl;
  /*  for ( it_flow = flows.begin(); it_flow != flows.end(); it_flow++ )
    {
        cout<<"\nFLOW value: "<<(*it_flow)->get_Terminal()->getConservativeValue();
    }*/
}
void ModelImpl::run(int inicial, int final)
{

}
void ModelImpl::remove(SystemImpl* s)
{
    for ( it_system = systems.begin(); it_system != systems.end(); it_system++ )
    {
        if(s == (*it_system))
        {
            systems.erase(it_system);
        }
    }
}

void ModelImpl::remove(FlowImpl* f)
{
    for ( it_flow = flows.begin(); it_flow != flows.end(); it_flow++ )
    {
        if(f == (*it_flow))
        {
            flows.erase(it_flow);
        }
    }
}

bool ModelImpl::search(SystemImpl* s)
{
    for ( it_system = systems.begin();it_system!= systems.end(); it_system++ )
    {
        if(s == (*it_system))
        {
            return true;
        }
    }
    return false;
}
bool ModelImpl::search(FlowImpl* f)
{
    for ( it_flow = flows.begin();it_flow!= flows.end(); it_system++ )
    {
        if(f == (*it_flow))
        {
            return true;
        }
    }
    return false;
}

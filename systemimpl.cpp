#include "systemimpl.h"

SystemImpl::SystemImpl()
{
	energy = 0;
}
SystemImpl::SystemImpl(double e)
{
    energy = e;
}
System* SystemImpl::operator=(System* s)
{
    if(s == this) return this;
    energy = s.get_energy();
    return this;
}
void SystemImpl::set_energy(double eg)
{
    energy = eg;
}
double SystemImpl::get_energy()
{
    return energy;
}



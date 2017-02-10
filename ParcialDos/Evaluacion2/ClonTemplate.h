#pragma once

template <class Base, class SubClase>
class ClonTemplate : public Base
{
public:

    virtual void clonar(Base*& b)
    {
        b = new SubClase(dynamic_cast<SubClase&>(*this));    
    }
};
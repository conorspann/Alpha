
#include "poly_var.h"

PolyVar::PolyVar(std::string strRep):
    strVal(strRep),
    intVal(0),
    typesSet(Types::NUM_TYPES, false)
{
    typesSet[Types::STRING] = true;
    if((std::size_t s = strRep.find_first_not_of("0123456789")) == std::string::npos){
        intVal =  std::stoi(strRep);
        typesSet[Types::INT] = true;
    }
}

// Need to do checks to see if they've been set

PolyVar & PolyVar::operator+=(PolyVar & p)
{
    if(){ // if int is set

    }
    this->strVal += p.getStrVal();
    this->intVal += p.getIntVal();
}

PolyVar & PolyVar::operator-=(PolyVar & p)
{
    this->intVal -= p.getIntVal();
}

PolyVar & PolyVar::operator*=(PolyVar & p)
{
    this->intVal *= p.getIntVal();
}

PolyVar & PolyVar::operator/=(PolyVar & p)
{
    this->intVal /= p.getIntVal();
}

PolyVar & PolyVar::operator%=(PolyVar & p)
{
    this->intVal %= p.getIntVal();
}

void PolyVar::setStrVal(std::string newStrVal)
{
    strVal = newStrVal;
    typesSet[Types::STRING] = true;
}

void PolyVar::setIntVal(int newIntVal)
{
    intVal = newIntVal;
    typesSet[Types::INT] = true;
}

std::string PolyVar::getStrVal()
{
    return strVal;
}

int PolyVar::getIntVal()
{
    return intVal;
}

std::vector<bool> PolyVar::getTypesSet()
{
    return typesSet;
}


#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>

class PolyVar{
public:
    enum class Types{
        STRING = 0,
        INT    = 1,

        NUM_TYPES
    };
    PolyVar(std::string);
    PolyVar & operator+=(PolyVar & p);
    PolyVar & operator-=(PolyVar & p);
    PolyVar & operator*=(PolyVar & p);
    PolyVar & operator/=(PolyVar & p);
    PolyVar & operator%=(PolyVar & p);
    std::string getStrVal();
    int getIntVal();
    std::vector<bool> getTypesSet();
private:
    std::vector<bool> typesSet;
    std::string strVal;
    int intVal;
    bool intSet, stringSet;
};

#endif // VARIABLE_H

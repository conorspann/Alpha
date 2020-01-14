
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <vector>
#include <map>

class Calculator{
public:
    Calculator();
    bool isSymbol(char);
    std::string calculate(std::vector<std::pair<std::string, int>>);
private:
    //typedef void (Calculator::*operation)(int*,int);
    template<class T>
    using templateOps = void(Calculator::*)(T*, T);
    const char symbols[8] = {'+','-','*','/','%','=','<','>'};
    std::map<char, templateOps<int>> intOpMap;

    typedef void (Calculator::*intOp)(int*, int);

    intOp setCurrentOperation(std::string);

    template<class T>
    void add(T*, T);
    template<class T>
    void subtract(T*, T);
    template<class T>
    void multiply(T*, T);
    template<class T>
    void divide(T*, T);
    template<class T>
    void remainder(T*, T);
    template<class T>
    void equals(T*, T);
    template<class T>
    void less_than(T*, T);
    template<class T>
    void greater_than(T*, T);
};

#endif // CALCULATOR_H


#include <algorithm>
#include <iterator>

#include "../../include/runtime/calculator.h"
#include "../../include/commands/command.h"

Calculator::Calculator()
{
    intOpMap.insert(std::pair<char, templateOps<int>>(symbols[0], add));
    intOpMap.insert(std::pair<char, templateOps<int>>(symbols[1], subtract));
    intOpMap.insert(std::pair<char, templateOps<int>>(symbols[2], multiply));
    intOpMap.insert(std::pair<char, templateOps<int>>(symbols[3], divide));
    intOpMap.insert(std::pair<char, templateOps<int>>(symbols[4], remainder));
    intOpMap.insert(std::pair<char, templateOps<int>>(symbols[5], equals));
    intOpMap.insert(std::pair<char, templateOps<int>>(symbols[6], less_than));
    intOpMap.insert(std::pair<char, templateOps<int>>(symbols[7], greater_than));
}


bool Calculator::isSymbol(char c)
{
    return std::find(std::begin(symbols), std::end(symbols), c) != std::end(symbols);
}

std::string Calculator::calculate(std::vector<std::pair<std::string, int>> params)
{
    /** Maybe for floats, keep separate track of decimal part, if greater than zero by end,
     result is a float

     maybe keep track of a string flag, if a string exists in the calculation,
     concatenate rather than add?

     maybe need to implement some kind of bidmas + ordering brackets
        maybe having a concatenation operator will help, since only need to do int calcs if theres no concat op
     Should return type as well?
     */
    if(params.size() < 2){
        return params[0].first;
    }

    int intResult = 0;
    std::string strResult;
    bool isString = false;
    intOp currentOp = add;
    for(auto param : params){
        std::string paramStr = param.first;
        int paramType = param.second;
        if(isSymbol(paramStr[0])){ /** && if length == 1 ?? */
            currentOp = setCurrentOperation(paramStr);
            continue;
        }
        if(paramType == Command::Type::STRING){
            isString = true;
            if(intResult != 0){
                strResult = std::to_string(intResult);
            }
        }
        if(isString){
            strResult += paramStr;
        }else{
            (this->*currentOp)(&intResult, std::stoi(paramStr));
        }
    }

    if(isString){
        return strResult;
    }

    return std::to_string(intResult);
}

Calculator::intOp Calculator::setCurrentOperation(std::string paramStr)
{
    std::map<char, templateOps<int>>::iterator it = intOpMap.find(paramStr[0]);
    if(it != intOpMap.end()){
        return it->second;
    }

    return add;
}


template <class T>
void Calculator::add(T * total, T value)
{
    *total += value;
}

template <class T>
void Calculator::subtract(T * total, T value)
{
    *total -= value;
}

template <class T>
void Calculator::multiply(T * total, T value)
{
    *total *= value;
}

template <class T>
void Calculator::divide(T * total, T value)
{
    *total /= value;
}

template <class T>
void Calculator::remainder(T * total, T value)
{
    *total %= value;
}

template <class T>
void Calculator::equals(T * total, T value)
{
    if(*total == value){
        *total = 1;
    }else{
        *total = 0; /** test this works */
    }
}

template <class T>
void Calculator::less_than(T * total, T value)
{
    if(*total < value){
        *total = 1;
    }else{
        *total = 0; /** test this works */
    }
}

template <class T>
void Calculator::greater_than(T * total, T value)
{
    if(*total > value){
        *total = 1;
    }else{
        *total = 0; /** test this works */
    }
}

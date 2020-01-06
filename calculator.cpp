
#include <algorithm>
#include <iterator>

#include "calculator.h"

#include "command.h"

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
    std::string result(params[0].first);
    if(params.size() > 1){
        int r = 0;
        void (Calculator::*currentOp)(int*, int) = add;
        for(auto i : params){
            if(isSymbol(i.first[0])){ /** && if length == 1 ?? */
                std::map<char, templateOps<int>>::iterator it = intOpMap.find(i.first[0]);
                if(it != intOpMap.end()){
                    currentOp = it->second;
                }
                continue;
            }
            /** TODO: Enable string/int etc concatenation */
            //  for now bomb out an error if string cant be converted to int
            if(i.second == Command::Type::STRING){
                std::string errMsg = "Error: Cannot calculate using non-numeric value: " + i.first + " In expression: ";
                for(auto j : params){
                    errMsg += j.first;
                }
                throw std::runtime_error(errMsg);
            }
            (this->*currentOp)(&r, std::stoi(i.first)); // doesn't work for strings
            /**
                maybe always set the first param to result first i.e. no add DONE=Y
                also make concatenation operator for string/int additions    DONE=N
                otherwise throw type/wrong operator exception                DONE=N

                if cannot be converted to int

                WARNING: if do decide to use concatenation operator, beware of the '.''s in decimals
                i.e. 3.2 != 3 concatenate 2 and in strings
            */
        }
        result = std::to_string(r);
    }

    return result;
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

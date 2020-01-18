
#include "../../include/formatter/formatter.h"

#include <iostream>
#include <vector>
#include <string>

Formatter::Formatter()
{

}

std::string Formatter::removeWhiteSpace(std::string line)
{
    std::string newLine;
    bool noRemove = false;
    for(int i = 0; i < line.length(); i++){
        char c = line[i];
        if(c == '\"'){
            noRemove = !noRemove;
        }
        if(!isWhiteSpace(c) || noRemove){
            newLine += c;
        }
    }

    return newLine;
}

bool Formatter::isWhiteSpace(char c)
{
    return (c == ' ' || c == '\t');
}

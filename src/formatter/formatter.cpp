
#include "../../include/formatter/formatter.h"

#include <iostream>
#include <vector>
#include <string>

Formatter::Formatter()
{

}

std::vector<std::string> Formatter::removeWhiteSpace(std::vector<std::string> lines)
{
    std::vector<std::string> formattedLines;
    for(int lineNumber = 0 ; lineNumber < lines.size(); lineNumber++){
        std::string line = lines[lineNumber];
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
        formattedLines.push_back(newLine);
    }

    return formattedLines;
}

bool Formatter::isWhiteSpace(char c)
{
    return (c == ' ' || c == '\t');
}

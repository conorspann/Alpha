
#include "../../include/formatter/formatter.h"

#include <iostream>
#include <vector>
#include <string>

Formatter::Formatter()
{

}

/**

formatting so words and symbols are separated with single spaces, with
blank lines removed and no white-space at start of line


need to do more tests, and change parser so it takes the new format

*/

std::vector<std::string> Formatter::removeWhiteSpace(std::vector<std::string> lines)
{
    std::vector<std::string> formattedLines;
    for(int lineNumber = 0 ; lineNumber < lines.size(); lineNumber++){
        std::string line = lines[lineNumber];
        if(line == ""){
            continue;
        }
        std::string newLine = removeInitialWhiteSpace(line);
        newLine = addSymbolWhiteSpace(newLine);
        newLine = removeDuplicateWhiteSpace(newLine);


        if(!newLine.empty()){
            formattedLines.push_back(newLine);
        }
    }

    for(auto i : formattedLines){
        std::cout << "[" << i << "]" << std::endl;
    }
    throw std::runtime_error("test remove me");

    return formattedLines;
}

bool Formatter::isWhiteSpace(char c)
{
    return (c == ' ' || c == '\t');
}

std::string Formatter::removeInitialWhiteSpace(std::string line)
{
    std::string newLine;
    int startPos = 0;
    for(int i = 0; i < line.length(); i++){
        char c = line[i];
        if(!isWhiteSpace(c)){
            startPos = i;
            break;
        }
    }
    newLine = line.substr(startPos, std::string::npos);

    return newLine;
}

std::string Formatter::addSymbolWhiteSpace(std::string line)
{
    std::string tempLine;
    bool isString = false;
    for(int  i = 0; i < line.length(); i++){
        char c = line[i];
        char nextChar = line[i+1];

        if(c == '\"'){
            isString = !isString;
        }

        if(isSymbol(c) && !isString){
            tempLine += " ";
        }
        tempLine += c;
        if(isSymbol(c) && !isString){
            tempLine += " ";
        }
    }


    return tempLine;
}

std::string Formatter::removeDuplicateWhiteSpace(std::string line)
{
    std::string newLine;
    bool addWhiteSpace = false;
    bool isString = false;
    for(int i = 0 ; i < line.length(); i++){
        char c = line[i];
        if(c == '\"'){
            isString = !isString;
        }
        if(isString){
            newLine += c;
            continue;
        }
        if(!isWhiteSpace(c)){
            addWhiteSpace = true;
        }
        if((isWhiteSpace(c) && addWhiteSpace)){
            newLine += c;
            addWhiteSpace = false;
        }else if(!isWhiteSpace(c) ){
            newLine += c;
        }
    }

    return newLine;
}

bool Formatter::isSymbol(char c)
{
    std::string charStr(1, c);

    return symbols.find(charStr) != std::string::npos;
}

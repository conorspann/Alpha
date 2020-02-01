

#include <iostream>
#include <vector>
#include <string>

#include "../../include/formatter/formatter.h"
#include "../../include/formatter/formatted_data.h"

static const std::string symbols = "+-*/?%@=<>,()";
static const std::string whiteSpaceChars = " \t";


Formatter::Formatter()
{

}

std::vector<std::string> Formatter::removeBlankLines(std::vector<std::string> lines)
{
    std::vector<std::string> formattedLines;
    for(int lineNumber = 0; lineNumber < lines.size(); lineNumber++){
        std::string line = lines[lineNumber];
        if(
            line.find_first_not_of(whiteSpaceChars) != std::string::npos
        ){
            formattedLines.push_back(line);
        }
    }

    return formattedLines;
}

std::vector<std::string> Formatter::formatLine(std::string line)
{
    std::vector<std::string> formattedLine;
    std::string segment;
    bool isString = false;
    for(int charNumber = 0; charNumber < line.length(); charNumber++){
        char c = line[charNumber];
        /**
            need special case for strings " "
         */

        if(c == '\"'){
            std::string strSeg(1, c);
            int quotePos;
            for(quotePos = charNumber + 1; quotePos < line.length(); quotePos++){
                char strC = line[quotePos];
                strSeg += strC;
                if(strC == '\"'){
                    formattedLine.push_back(strSeg);
                    charNumber = quotePos;
                    break;
                }
            }
            if(quotePos == line.length()){
                throw std::runtime_error("Error: String is missing end-quote.");
            }
            continue;
        }

        if(!isWhiteSpace(c)){
            if(isSymbol(c)){
                addSegment(formattedLine, segment);
                std::string symbol(1, c);
                formattedLine.push_back(symbol);
            }else{
                segment += c;
            }
        }
        if(charNumber == line.length() - 1 || isWhiteSpace(c)){
            addSegment(formattedLine, segment);
        }
    }

    return formattedLine;
}

std::vector<std::vector<std::string>> Formatter::formatLines(std::vector<std::string> rawLines)
{
    std::vector<std::vector<std::string>> formattedLines;
    for(auto line : rawLines){
        std::vector<std::string> formattedLine = formatLine(line);
        formattedLines.push_back(formattedLine);
    }

    return formattedLines;
}

bool Formatter::isWhiteSpace(char c)
{
    return (c == ' ' || c == '\t');
}

bool Formatter::isSymbol(char c)
{
    std::string charStr(1, c);

    return symbols.find(charStr) != std::string::npos;
}

void Formatter::addSegment(std::vector<std::string> & formattedLine, std::string & segment)
{
    if(segment != ""){
        formattedLine.push_back(segment);
        segment = "";
    }
}

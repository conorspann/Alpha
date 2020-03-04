

#include <iostream>
#include <vector>
#include <string>

#include "../../include/formatter/formatter.h"

static const std::string symbols = "+-*/?%@=<>,()";
static const std::string whiteSpaceChars = " \t";


std::vector<std::pair<int, std::string>> Formatter::removeBlankLines(std::vector<std::pair<int, std::string>> lines)
{
    std::vector<std::pair<int, std::string>> formattedLines;
    for(int lineNumber = 0; lineNumber < lines.size(); lineNumber++){
        int preservedLineNumber = lines[lineNumber].first;
        std::string line = lines[lineNumber].second;
        if(
            line.find_first_not_of(whiteSpaceChars) != std::string::npos
        ){
            formattedLines.push_back(std::pair<int, std::string>(preservedLineNumber, line));
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

std::vector<std::pair<int, std::vector<std::string>>> Formatter::formatLines(std::vector<std::pair<int, std::string>> rawLines)
{
    std::vector<std::pair<int, std::vector<std::string>>> formattedLines;
    for(auto line : rawLines){
        int preservedLineNumber = line.first;
        std::vector<std::string> formattedLine = formatLine(line.second);
        formattedLines.push_back(std::pair<int, std::vector<std::string>>(preservedLineNumber, formattedLine));
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

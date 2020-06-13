

#include <iostream>
#include <vector>
#include <string>

#include "../../include/formatter/formatter.h"
#include "../../include/exception/syntax_error.h"

static const std::string symbols = "+-*/?%@=<>,()";
static const std::string whiteSpaceChars = " \t";


std::vector<std::pair<int, std::string>> Formatter::removeBlankLines(std::vector<std::pair<int, std::string>> lines)
{
    std::vector<std::pair<int, std::string>> formattedLines;
    for(int lineNumber = 0; lineNumber < lines.size(); lineNumber++){
        int preservedLineNumber = lines[lineNumber].first;
        std::string line = lines[lineNumber].second;
        addNonBlankLine(line, preservedLineNumber, formattedLines);
    }

    return formattedLines;
}

void Formatter::addNonBlankLine(std::string line, int preservedLineNumber, std::vector<std::pair<int, std::string>> & formattedLines)
{
    if(
        line.find_first_not_of(whiteSpaceChars) != std::string::npos
    ){
        formattedLines.push_back(std::pair<int, std::string>(preservedLineNumber, line));
    }
}

std::vector<std::pair<int, std::vector<std::string>>> Formatter::tokeniseLines(std::vector<std::pair<int, std::string>> rawLines)
{
    std::vector<std::pair<int, std::vector<std::string>>> tokenisedLines;
    for(auto rawLine : rawLines){
        int preservedLineNumber = rawLine.first;
        std::vector<std::string> tokenisedLine = tokeniseLine(rawLine.second, preservedLineNumber);
        tokenisedLines.push_back(std::pair<int, std::vector<std::string>>(preservedLineNumber, tokenisedLine));
    }

    return tokenisedLines;
}

std::vector<std::string> Formatter::tokeniseLine(std::string rawLine, int preservedLineNumber)
{
    std::vector<std::string> tokenisedLine;
    std::string token;
    bool isString = false;
    for(int charNumber = 0; charNumber < rawLine.length(); charNumber++){
        char c = rawLine[charNumber];
        if(c == '\"'){
            tokeniseInlineString(rawLine, &charNumber, preservedLineNumber, tokenisedLine);
        }
        if(!isWhiteSpace(c)){
            if(isSymbol(c)){
                addSymbol(tokenisedLine, token, c);
            }else{
                token += c;
            }
        }
        if(charNumber == rawLine.length() - 1 || isWhiteSpace(c)){
            addSegment(tokenisedLine, token);
        }
    }

    return tokenisedLine;
}

void Formatter::tokeniseInlineString(std::string rawLine, int * charNumber, int preservedLineNumber, std::vector<std::string> & tokenisedLine)
{
    std::string extractedString = extractString(rawLine, *charNumber, preservedLineNumber);
    tokenisedLine.push_back(extractedString);
    *charNumber += extractedString.length() - 1;
}

std::string Formatter::extractString(std::string rawLine, int currentCharNumber, int preservedLineNumber)
{
    std::string extractedStr(1, '\"');
    int quotePos;
    for(quotePos = currentCharNumber + 1; quotePos < rawLine.length(); quotePos++){
        char strC = rawLine[quotePos];
        extractedStr += strC;
        if(strC == '\"'){
            break;
        }
    }
    checkForMissingEndQuote(quotePos, rawLine, preservedLineNumber);

    return extractedStr;
}

void Formatter::checkForMissingEndQuote(int quotePos, std::string rawLine, int preservedLineNumber)
{
    if(quotePos == rawLine.length()){
        throw SyntaxError("Error: String is missing end-quote.", preservedLineNumber);
    }
}

void Formatter::addSymbol(std::vector<std::string> & tokenisedLine, std::string & token, char c)
{
    addSegment(tokenisedLine, token);
    std::string symbol(1, c);
    tokenisedLine.push_back(symbol);
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

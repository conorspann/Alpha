
#include "../../include/init/command_extractor.h"
#include "../../include/init/extracted_line.h"
#include "../../include/formatter/formatter.h"

#include <iostream>
#include <vector>
#include <string>

CommandExtractor::CommandExtractor()
{

}

// Maybe split this class into other classes


ExtractedLine CommandExtractor::extract(std::vector<std::string> segmentedLine)
{
    if(segmentedLine.size() < 1){
        throw std::runtime_error("Error: Blank statement");
    }
    std::string cmdStr;
    std::vector<std::string> paramList;
    std::string firstSeg = segmentedLine[0];
    if(Formatter::isSymbol(firstSeg[0])){
        if(firstSeg != "@"){
            throw std::runtime_error("Error: Erroneous symbol in command.");
        }
        cmdStr = firstSeg;
        paramList = getDefineParamList(segmentedLine);
    }else{
        cmdStr = segmentedLine[0];
        paramList = getParamList(segmentedLine);
    }
    ExtractedLine extractedLine(cmdStr, paramList);

    return extractedLine;
}


std::vector<std::string> CommandExtractor::getParamList(std::vector<std::string> segmentedLine)
{
    std::vector<std::string> paramList;

    if(segmentedLine.size() < 2 || segmentedLine[0] == "Cmd"){
        return paramList;
    }
    std::string param;
    for(int segmentNumber = 2; segmentNumber < segmentedLine.size() - 1; segmentNumber++){
        std::string segment = segmentedLine[segmentNumber];
        if(segment == ","){
            paramList.push_back(param);
            param = "";
            continue;
        }
        param += segment;
        if(segmentNumber == segmentedLine.size() - 2){
            paramList.push_back(param);
            param = "";
        }
    }

    return paramList;
}


std::vector<std::string> CommandExtractor::getDefineParamList(std::vector<std::string> segmentedLine)
{
    std::vector<std::string> defineParamList;
    if(segmentedLine.size() < 4 || segmentedLine[2] != "="){
        throw std::runtime_error("Error: Malformed assignment.");
    }
    defineParamList.push_back(segmentedLine[1]);
    std::string params;
    for(int segmentNumber = 3; segmentNumber < segmentedLine.size(); segmentNumber++){
        params += segmentedLine[segmentNumber];
    }
    defineParamList.push_back(params);

    return defineParamList;
}


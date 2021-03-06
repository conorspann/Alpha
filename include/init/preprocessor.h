
#ifndef PRE_PROCESSOR_H
#define PRE_PROCESSOR_H

#include <vector>
#include <string>

#include "../init/command_data.h"
#include "../../include/init/file_loader.h"

class PreProcessor{
public:
    std::vector<std::pair<int, std::string>> includeFiles(std::string filename);
private:
    FileLoader loader;
    const char INCLUDE_CHAR = '#';
    const std::string INCLUDE_KEY_WORD = "gimme";
    std::vector<std::pair<int, std::string>> getFilenames(std::vector<std::string> rawData);
    std::vector<std::pair<int, std::string>> addLineNumbers(std::vector<std::string> rawData);
    std::string formatIncludeFilename(std::string rawFilename);
    void formatIncludeFilenames(std::vector<std::pair<int, std::string>> & rawFilenames);
    std::string extractFilename(std::string rawFilename, int startPosition);
    void insertIncludeData(std::vector<std::string> & rawData, std::vector<std::string> dataToInclude, int lineIndex);
    void adjustIncludeFileLineNumbers(std::vector<std::pair<int, std::string>> & files, int startFileIndex, int adjustment);
};

#endif // PRE_PROCESSOR_H



#include "../../include/init/preprocessor.h"

#include <iostream>

std::vector<std::pair<int, std::string>> PreProcessor::includeFiles(std::string filename)
{
    std::vector<std::string> rawData = loader.load(filename);

    std::vector<std::pair<int, std::string>> filesToInclude = getFilenames(rawData);

    if (filesToInclude.empty()) {
        return addLineNumbers(rawData);
    }

    for (int fileNumber = 0; fileNumber < filesToInclude.size(); fileNumber++) {
        filesToInclude[fileNumber].second = formatIncludeFilename(filesToInclude[fileNumber].second);
    }


    for ( int fileNumber = 0; fileNumber < filesToInclude.size(); fileNumber++ ) {
        std::pair<int, std::string> fileLineNumberPair = filesToInclude[fileNumber];
        std::vector<std::string> dataToInclude = loader.load(fileLineNumberPair.second);

        for ( int lineIndex = 0; lineIndex < rawData.size(); lineIndex++ ) {

            if ( lineIndex == fileLineNumberPair.first ) {
                rawData[lineIndex] = dataToInclude[0];
                int startLineIndex = lineIndex + 1;

                std::vector<std::string>::iterator rawDataIterator;
                rawDataIterator = rawData.begin() + startLineIndex;

                for (int dataToIncludeIndex = 1; dataToIncludeIndex < dataToInclude.size(); dataToIncludeIndex++) {
                    rawDataIterator = rawData.insert(rawDataIterator, dataToInclude[dataToIncludeIndex]);
                    rawDataIterator++;
                }

                if (fileNumber < filesToInclude.size() - 1) {
                    adjustIncludeFileLineNumbers(filesToInclude, fileNumber + 1, dataToInclude.size() - 1);
                }

                break;
            }
        }
    }

    return addLineNumbers(rawData);
}



std::vector<std::pair<int, std::string>> PreProcessor::getFilenames(std::vector<std::string> rawData)
{
    std::vector<std::pair<int, std::string>> filesToInclude;

    for (int lineNumber = 0; lineNumber < rawData.size(); lineNumber++) {
        std::string line = rawData[lineNumber];
        for (int charNumber = 0; charNumber < line.length(); charNumber++) {
            char symbol = line[charNumber];
            if (symbol == INCLUDE_CHAR) {
                std::string keyWord = line.substr(charNumber + 1, INCLUDE_KEY_WORD.length());
                if (keyWord != INCLUDE_KEY_WORD) {
                    break;
                }

                charNumber += 1 + INCLUDE_KEY_WORD.length();

                std::string rawFilename = line.substr(charNumber, std::string::npos);
                std::pair<int, std::string> filenameLineNumberPair(lineNumber, rawFilename);
                filesToInclude.push_back(filenameLineNumberPair);

                break;
            }
        }
    }

    return filesToInclude;
}

std::vector<std::pair<int, std::string>> PreProcessor::addLineNumbers(std::vector<std::string> rawData)
{
    std::vector<std::pair<int, std::string>> linedStatements;

    for (int resultLineNumber = 0; resultLineNumber < rawData.size(); resultLineNumber++) {
        std::pair<int, std::string> lineNumberPair(resultLineNumber + 1, rawData[resultLineNumber]);
        linedStatements.push_back(lineNumberPair);
    }

    return linedStatements;
}

void PreProcessor::adjustIncludeFileLineNumbers(std::vector<std::pair<int, std::string>> & files, int startFileIndex, int adjustment)
{
    for (int fileIndex = startFileIndex; fileIndex < files.size(); fileIndex++) {
        files[fileIndex].first += adjustment;
    }
}

std::string PreProcessor::formatIncludeFilename(std::string rawFilename)
{
    std::string formattedFilename;
    for (int charNumber = 0; charNumber < rawFilename.length(); charNumber++) {
        char symbol = rawFilename[charNumber];
        if (symbol == '\"') {
            for (int charToAddNumber = charNumber + 1; charToAddNumber < rawFilename.length(); charToAddNumber++) {
                symbol = rawFilename[charToAddNumber];
                if (symbol == '\"') {
                    break;
                }

                formattedFilename += symbol;
            }

            break;
        }
    }

    return formattedFilename;
}

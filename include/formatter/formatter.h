
#ifndef FORMATTER_H
#define FORMATTER_H

#include <string>
#include <vector>

class Formatter{
public:
    std::vector<std::pair<int, std::string>> removeBlankLines(std::vector<std::pair<int, std::string>>);
    std::vector<std::pair<int, std::vector<std::string>>> tokeniseLines(std::vector<std::pair<int, std::string>> );
    static bool isWhiteSpace(char c);
    static bool isSymbol(char c);
private:
    void addNonBlankLine(std::string line, int preservedLineNumber, std::vector<std::pair<int, std::string>> & formattedLines);
    std::vector<std::string> tokeniseLine(std::string line, int);
    void tokeniseInlineString(std::string rawLine, int * charNumber, int preservedLineNumber, std::vector<std::string> & tokenisedLine);
    std::string extractString(std::string, int, int);
    void checkForMissingEndQuote(int quotePos, std::string rawLine, int preservedLineNumber);
    void addSymbol(std::vector<std::string> & tokenisedLine, std::string & token, char c);
    void addSegment(std::vector<std::string> &, std::string &);
};

#endif // FORMATTER_H


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
    std::vector<std::string> tokeniseLine(std::string line, int);
    std::string extractString(std::string, int, int);
    void addSegment(std::vector<std::string> &, std::string &);
};

#endif // FORMATTER_H

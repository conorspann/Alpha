
#ifndef FORMATTER_H
#define FORMATTER_H

#include <string>
#include <vector>

class Formatter{
public:
    std::vector<std::pair<int, std::string>> removeBlankLines(std::vector<std::pair<int, std::string>>);
    std::vector<std::string> formatLine(std::string line);
    std::vector<std::pair<int, std::vector<std::string>>> formatLines(std::vector<std::pair<int, std::string>> );
    static bool isWhiteSpace(char c);
    static bool isSymbol(char c);
private:
    void addSegment(std::vector<std::string> &, std::string &);
};

#endif // FORMATTER_H

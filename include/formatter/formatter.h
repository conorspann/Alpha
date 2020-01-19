
#ifndef FORMATTER_H
#define FORMATTER_H

#include <string>
#include <vector>

class Formatter{
public:
    Formatter();
    std::vector<std::string> removeWhiteSpace(std::vector<std::string>);
private:
    bool isWhiteSpace(char);
};

#endif // FORMATTER_H

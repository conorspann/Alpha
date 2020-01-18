
#ifndef FORMATTER_H
#define FORMATTER_H

#include <string>
#include <vector>

class Formatter{
public:
    Formatter();
    std::string removeWhiteSpace(std::string);
private:
    bool isWhiteSpace(char);
};

#endif // FORMATTER_H

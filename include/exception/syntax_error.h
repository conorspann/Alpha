
#ifndef SYNTAX_ERROR_H
#define SYNTAX_ERROR_H

#include <stdexcept>

class SyntaxError: public std::runtime_error{
public:
    SyntaxError(std::string, int);
    const char * what() const throw();
private:
    const std::string lineMsg = " At line number: ";
    std::string fullMsg;
    const char * cFullMsg;
};

#endif // SYNTAX_ERROR_H

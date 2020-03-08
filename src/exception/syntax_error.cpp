
#include "../../include/exception/syntax_error.h"


SyntaxError::SyntaxError(std::string baseMsg, int lineNumber):
    std::runtime_error(baseMsg)
{
    fullMsg = baseMsg + lineMsg + std::to_string(lineNumber);
    cFullMsg = fullMsg.c_str();
}

const char * SyntaxError::what() const throw()
{
    return cFullMsg;
}

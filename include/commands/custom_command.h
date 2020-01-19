
#ifndef CUSTOM_COMMAND_H
#define CUSTOM_COMMAND_H

#include <string>
#include <vector>

class CustomCommand{
public:
    CustomCommand(std::string, std::vector<std::string>);
    void jumpToCommand();
    void setLineNumber(int);
    int getLineNumber();
    std::string getName();
    std::vector<std::string> getParams();
private:
    int lineNumber;
    std::string name;
    std::vector<std::string> params;
};

#endif // CUSTOM_COMMAND_H

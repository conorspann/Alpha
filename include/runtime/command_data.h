
#ifndef COMMAND_DATA
#define COMMAND_DATA

#include <string>
#include <vector>

class CommandData{
public:
    CommandData(int, std::string, std::vector<std::string>);
    int getLineNumber();
    std::string getName();
    std::vector<std::string> getParams();
private:
    int lineNumber;
    std::string name;
    std::vector<std::string> params;
};

#endif // COMMAND_DATA

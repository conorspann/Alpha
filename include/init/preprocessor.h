
#ifndef PRE_PROCESSOR_H
#define PRE_PROCESSOR_H

#include <vector>
#include <string>

class PreProcessor{
public:
    PreProcessor(std::vector<std::string>);
    std::vector<std::string> getCustomCommands();
};

#endif // PRE_PROCESSOR_H

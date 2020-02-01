
#ifndef PRE_PROCESSOR_H
#define PRE_PROCESSOR_H

#include <vector>
#include <string>

#include "../runtime/command_data.h"

class PreProcessor{
public:
    PreProcessor();
    std::vector<std::string> includeFiles(std::vector<std::string>);
};

#endif // PRE_PROCESSOR_H

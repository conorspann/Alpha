
#ifndef MEMORY_DUMP_H
#define MEMORY_DUMP_H

#include "command.h"

#include <memory>

class MemoryDump: public Command{
public:
    MemoryDump(std::vector<std::string> params);
    void execute(Environment &, std::vector<std::unique_ptr<Command>> &, int *);
    int getNumParams();
    std::string getName();
private:

};

#endif // MEMORY_DUMP_H

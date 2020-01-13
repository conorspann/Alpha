
#ifndef ENDIF_H
#define ENDIF_H

#include "command.h"

class EndIf: public Command{
public:
    EndIf(std::vector<std::string> p);
    void execute(Resolver &, std::map<std::string, std::pair<std::string, int>> * , std::vector<std::unique_ptr<Command>> &, int *);
    int getNumParams();
    std::string getName();
};

#endif // ENDIF_H

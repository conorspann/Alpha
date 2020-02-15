
#ifndef ENDIF_H
#define ENDIF_H

#include "command.h"

class EndIf: public Command{
public:
    EndIf(std::vector<std::string> p);
    void execute(Environment &, int *);
    int getNumParams();
    std::string getName();
};

#endif // ENDIF_H

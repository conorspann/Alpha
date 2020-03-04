
#ifndef ASSIGN_H
#define ASSIGN_H

#include "command.h"
#include <string>
#include <vector>

//maybe make the formatter parse assign command params differently

class Assign: public Command{
public:
    Assign(std::vector<std::string>, int);
    void execute(Environment &, int *);
    int getNumParams();
    std::string getName();
};

#endif // ASSIGN_H

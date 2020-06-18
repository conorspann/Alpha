
#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>

#include "../runtime/environment.h"

class Command{
public:
    enum Type{ // change to better solution, since this is needed by Command sub class and Resolver
        STRING,
        INT,
        SYMBOL,
        UNKNOWN
    };
    Command(std::vector<std::string>, int);
    virtual void execute(Environment &, int *) =0;
    virtual int getNumParams() =0;
    virtual std::string getName() =0;
    bool hasCorrectNumParams();
    int getPreservedLineNumber();
    std::string toString();
protected:
    std::vector<std::string> params;
    int preservedLineNumber;
};

#endif // COMMAND_H

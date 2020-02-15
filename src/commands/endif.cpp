

#include "../../include/commands/endif.h"
#include "../../include/runtime/environment.h"

EndIf::EndIf(std::vector<std::string> p):
    Command(p)
{

}

void EndIf::execute(Environment & environment, int *)
{
    // do nothing ??
}

int EndIf::getNumParams()
{
    return 0;
}

std::string EndIf::getName()
{
    return "EndIf";
}

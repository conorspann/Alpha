


#include "../../include/commands/clear_window.h"
#include "../../include/runtime/environment.h"

ClearWindow::ClearWindow(std::vector<std::string> params):
    Command(params)
{

}

void ClearWindow::execute(Environment & environment, int *)
{
    DataPool & dataPool = environment.getDataPool();
    Resolver & resolver = environment.getResolver();
    std::pair<std::string, int> handleVar = resolver.resolveVariable(params[0], dataPool);
    std::string handleStr = handleVar.first;
    if(resolver.determineType(handleStr) != Command::Type::INT){
        throw std::runtime_error("Error: window handle must be integer.");
    }

    int handle = std::stoi(handleStr);
    std::vector<Window> & windows = environment.getWindows();
    if(handle < 0 || handle >= windows.size()){
        throw std::runtime_error("Error: window handle out of bounds");
    }
    windows[handle].clearWindow();

}

int ClearWindow::getNumParams()
{
    return 1;
}

std::string ClearWindow::getName()
{
    return "ClearWindow";
}


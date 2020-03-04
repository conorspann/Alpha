
#include "../../include/commands/create_window.h"
#include "../../include/commands/command.h"
#include "../../include/runtime/resolver.h"

#include <vector>
#include <string>

CreateWindow::CreateWindow(std::vector<std::string> params, int lineNumber):
    Command(params, lineNumber)
{

}

void CreateWindow::execute(Environment & environment, int * cmdPtr)
{
    DataPool & dataPool = environment.getDataPool();
    Resolver & resolver = environment.getResolver();
    std::vector<Window> & windows = environment.getWindows();
    std::string windowName = resolver.resolve(params[0], dataPool);
    std::string widthStr = params[1];
    std::string heightStr = params[2];
    if(resolver.determineType(widthStr) != Command::Type::INT || resolver.determineType(heightStr) != Command::Type::INT){
        throw std::runtime_error("Error: window width and height need to be integers.");
    }
    int width = std::stoi(widthStr);
    int height = std::stoi(heightStr);

    std::string handleVarName = params[3];
    std::pair<std::string, int> & variable = resolver.resolveVariable(handleVarName, dataPool);

    variable.first = environment.getNewWindowHandle();

    Window window(windowName, width, height);
    windows.push_back(window);
}

int CreateWindow::getNumParams()
{
    return 4;
}

std::string CreateWindow::getName()
{
    return "CreateWindow";
}

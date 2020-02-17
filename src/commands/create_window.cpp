
#include "../../include/commands/create_window.h"
#include "../../include/commands/command.h"
#include "../../include/runtime/resolver.h"

#include <vector>
#include <string>

CreateWindow::CreateWindow(std::vector<std::string> params):
    Command(params)
{

}

void CreateWindow::execute(Environment & environment, int * cmdPtr)
{
    std::map<std::string, std::pair<std::string, int>> & globalDataPool = environment.getGlobalDataPool();
    Resolver & resolver = environment.getResolver();
    std::vector<Window> & windows = environment.getWindows();
    std::string windowName = resolver.resolve(params[0], globalDataPool);
    std::string widthStr = params[1];
    std::string heightStr = params[2];
    if(resolver.determineType(widthStr) != Command::Type::INT || resolver.determineType(heightStr) != Command::Type::INT){
        throw std::runtime_error("Error: window width and height need to be integers.");
    }
    int width = std::stoi(widthStr);
    int height = std::stoi(heightStr);

    std::map<std::string, std::pair<std::string, int>>::iterator it;
    std::string handleVarName = params[3];
    it = globalDataPool.find(handleVarName);
    if(it == globalDataPool.end()){
        std::string errMsg = "Error: parameter variable: ";
        errMsg += handleVarName;
        errMsg += " does not exist";
        throw std::runtime_error(errMsg);
    }
    it->second.first = environment.getNewWindowHandle();

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

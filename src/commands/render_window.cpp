


#include "../../include/commands/render_window.h"
#include "../../include/runtime/environment.h"

RenderWindow::RenderWindow(std::vector<std::string> params):
    Command(params)
{

}

void RenderWindow::execute(Environment & environment, int *)
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
    windows[handle].render();



}

int RenderWindow::getNumParams()
{
    return 1;
}

std::string RenderWindow::getName()
{
    return "RenderWindow";
}

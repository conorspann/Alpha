
#include "../../include/commands/show_window.h"

ShowWindow::ShowWindow(std::vector<std::string> params, int lineNumber):
    Command(params, lineNumber)
{

}

void ShowWindow::execute(Environment & environment, int * cmdPtr)
{
    DataPool & dataPool = environment.getDataPool();
    Resolver & resolver = environment.getResolver();
    std::vector<Window> & windows = environment.getWindows();
    std::string windowHandleStr = resolver.resolve(params[0], dataPool);
    int windowHandle = std::stoi(windowHandleStr);
    if(windowHandle < 0 || windowHandle >= windows.size()){
        throw std::runtime_error("Error: window handle invalid.");
    }
    windows[windowHandle].show();
}

int ShowWindow::getNumParams()
{
    return 1;
}

std::string ShowWindow::getName()
{
    return "ShowWindow";
}



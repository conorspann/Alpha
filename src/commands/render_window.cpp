

#include "../../include/commands/render_window.h"
#include "../../include/runtime/environment.h"
#include "../../include/exception/syntax_error.h"


RenderWindow::RenderWindow(std::vector<std::string> params, int lineNumber):
    Command(params, lineNumber)
{

}

void RenderWindow::execute(Environment & environment, int *)
{
    DataPool & dataPool = environment.getDataPool();
    Resolver & resolver = environment.getResolver();
    std::pair<std::string, int> handleVar = resolver.resolveVariable(params[0], dataPool);
    std::string handleStr = handleVar.first;
    if(resolver.determineType(handleStr) != Command::Type::INT){
        throw SyntaxError("Error: window handle must be integer.", getPreservedLineNumber());
    }

    int handle = std::stoi(handleStr);
    std::vector<Window> & windows = environment.getWindows();
    if(handle < 0 || handle >= windows.size()){
        throw SyntaxError("Error: window handle out of bounds.", getPreservedLineNumber());
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

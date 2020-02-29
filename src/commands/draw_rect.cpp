

#include "../../include/commands/draw_rect.h"
#include "../../include/runtime/environment.h"

DrawRect::DrawRect(std::vector<std::string> params):
    Command(params)
{

}

void DrawRect::execute(Environment & environment, int *)
{
    DataPool & dataPool = environment.getDataPool();
    Resolver & resolver = environment.getResolver();
    std::string xStr = resolver.resolve(params[0], dataPool);
    std::string yStr = resolver.resolve(params[1], dataPool);
    std::string wStr = resolver.resolve(params[2], dataPool);
    std::string hStr = resolver.resolve(params[3], dataPool);
    std::pair<std::string, int> handleVar = resolver.resolveVariable(params[4], dataPool);
    std::string handleStr = handleVar.first;
    if(
       resolver.determineType(xStr) != Command::Type::INT ||
       resolver.determineType(yStr) != Command::Type::INT ||
       resolver.determineType(wStr) != Command::Type::INT ||
       resolver.determineType(hStr) != Command::Type::INT ||
       resolver.determineType(handleStr) != Command::Type::INT
    ){
        throw std::runtime_error("Error: draw rect parameters must be integers.");
    }
    int xPos = std::stoi(xStr);
    int yPos = std::stoi(yStr);
    int wPos = std::stoi(wStr);
    int hPos = std::stoi(hStr);
    int handle = std::stoi(handleStr);
    std::vector<Window> & windows = environment.getWindows();
    if(handle < 0 || handle >= windows.size()){
        throw std::runtime_error("Error: window handle out of bounds");
    }
    windows[handle].drawRect(xPos, yPos, wPos, hPos);



}

int DrawRect::getNumParams()
{
    return 5;
}

std::string DrawRect::getName()
{
    return "DrawRect";
}

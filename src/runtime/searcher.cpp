

#include "../../include/runtime/searcher.h"

#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

Searcher::Searcher()
{

}

int Searcher::findLabel(std::string startLabel, std::string endLabel, int direction, bool jumpPast, std::vector<std::unique_ptr<Command>> & cmds, int * cmdPtr)
{
    int nestedLevel = 0;
    if(direction > 0 ){
        direction = 1;
    }else{
        direction = -1;
    }
    for(int i = (*cmdPtr) + direction; i < cmds.size(); i += direction){
        if(cmds[i]->getName() == startLabel){
            nestedLevel++;
        }
        if(cmds[i]->getName() == endLabel){
            if(nestedLevel == 0){
                if(direction == -1){
                    return i - 1;
                }
                return i;
            }
            nestedLevel--;
        }
    }
    std::string errMsg = "Error: ";
    errMsg += startLabel;
    errMsg += " statement has no ";
    errMsg += endLabel;
    throw std::runtime_error(errMsg);
}



#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

#include "../../include/runtime/searcher.h"


Searcher::Searcher(std::vector<std::string> labels):
    labels(labels)
{

}

int Searcher::findLabel(std::string startLabel, std::string endLabel, int reqDirection, int * cmdPtr)
{
    int nestedLevel = 0;
    int direction = reqDirection > 0 ? 1 : -1;
    for(int i = (*cmdPtr) + direction; i < labels.size(); i += direction){
        if(labels[i] == startLabel){
            nestedLevel++;
        }
        if(labels[i] == endLabel){
            if(nestedLevel == 0){
                if(direction == -1){
                    return i - 1;
                }
                return i;
            }
            nestedLevel--;
        }
    }

    throwLabelError(startLabel, endLabel);
}

void Searcher::throwLabelError(std::string startLabel, std::string endLabel)
{
    std::string errMsg = "Error: ";
    errMsg += startLabel;
    errMsg += " statement has no ";
    errMsg += endLabel;
    throw std::runtime_error(errMsg);
}

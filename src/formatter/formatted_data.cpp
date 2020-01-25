
#include "../../include/formatter/formatted_data.h"


FormattedData(std::vector<std::vector<std::string>> formattedData):
    formattedData(formattedData)
{

}

std::string FormattedData::getSegment(int x, int y)
{
    std::string segment;
    if(validYPos(y)){
        std::vector<std::string> lineSegments = formattedData[y];
        if(validXPos(lineSegments, x)){
            segment = lineSegments[x];
        }
    }
    return segment;
}

bool FormattedData::validYPos(int y)
{
    return y >= 0 && y < formattedData.size();
}

bool FormattedData::validXPos(std::vector<std::string> lineSegments, int x)
{
    return x >= 0 && x < lineSegments.size();
}

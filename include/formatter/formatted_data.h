
#ifndef FORMATTED_DATA_H
#define FORMATTED_DATA_H

class FormattedData{
public:
    FormattedData(std::vector<std::vector<std::string>>);
    std::string getSegment(int , int);
private:
    std::string symbols = "";
    std::vector<std::vector<std::string>> formattedData;
    bool validYPos(int);
};

#endif // FORMATTED_DATA_H

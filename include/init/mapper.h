
#ifndef MAPPER_H
#define MAPPER_H

#include "../commands/command.h"
#include "../runtime/command_data.h"

#include <map>
#include <string>
#include <memory>

class Mapper{
public:
    Mapper();
    std::unique_ptr<Command> getNewCommand(std::string, std::vector<std::string>, std::vector<CommandData> &, int);
private:
    typedef std::unique_ptr<Command> (Mapper::*commandGenerator)(std::vector<std::string>, int);
    std::map<std::string, commandGenerator> commandMap;

    std::unique_ptr<Command> getCustomCommandCall(std::string, std::vector<CommandData> &, std::vector<std::string>, int);

    std::unique_ptr<Command> genAssign(std::vector<std::string>, int);
    std::unique_ptr<Command> genConsoleOut(std::vector<std::string>, int);
    std::unique_ptr<Command> genConsoleOutLn(std::vector<std::string>, int);
    std::unique_ptr<Command> genConsoleIn(std::vector<std::string>, int);
    std::unique_ptr<Command> genMemoryDump(std::vector<std::string>, int);
    std::unique_ptr<Command> genIf(std::vector<std::string>, int);
    std::unique_ptr<Command> genEndIf(std::vector<std::string>, int);
    std::unique_ptr<Command> genWhile(std::vector<std::string>, int);
    std::unique_ptr<Command> genEndWhile(std::vector<std::string>, int);
    std::unique_ptr<Command> genCmd(std::vector<std::string>, int);
    std::unique_ptr<Command> genEndCmd(std::vector<std::string>, int);
    std::unique_ptr<Command> genWait(std::vector<std::string>, int);
    std::unique_ptr<Command> genCreateWindow(std::vector<std::string>, int);
    std::unique_ptr<Command> genShowWindow(std::vector<std::string>, int);
    std::unique_ptr<Command> genHideWindow(std::vector<std::string>, int);
    std::unique_ptr<Command> genClearWindow(std::vector<std::string>, int);
    std::unique_ptr<Command> genRenderWindow(std::vector<std::string>, int);
    std::unique_ptr<Command> genDrawRect(std::vector<std::string>, int);
};

#endif // MAPPER_H

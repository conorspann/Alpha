
#include "catch.h"

#include "parser.h"

#include "command.h"
#include "console_out.h"

TEST_CASE("test parse valid commands")
{
    std::vector<std::unique_ptr<Command> expected;
    std::unique_ptr<Command> cmdPtr = std::make_unique<ConsoleOut>("hello");
    expected.push_back(std::move(cmdPtr));
    std::vector<std::string> inputData = {"ConsoleOut(\"hello\")", "ConsoleOut(\"hello\")"};
    Parser parser(inputData);
    std::vector<std::unique_ptr<Command>> cmds = parser.parse(); // make command ptr vector to compare to for assert
}

TEST_CASE("test parse invalid commands")
{
    std::vector<std::string> data = {"invalid()", "ConsoleOut(invalid, invalid, invalid)"};
    Parser parser(data);
    std::vector<std::unique_ptr<Command>> cmds = parser.parse(); // assert throws exception
}


#include "../../include/catch.h"

#include "../../include/init/parser.h"

#include "../../include/commands/command.h"
#include "../../include/commands/console_out.h"

#include <iostream>

TEST_CASE("test parse valid commands")
{
    std::vector<std::unique_ptr<Command>> expected;
    std::vector<std::string> testParams = {"hello there"};
    std::unique_ptr<Command> cmdPtr = std::make_unique<ConsoleOut>(testParams);
    expected.push_back(std::move(cmdPtr));
    std::vector<std::string> inputData = {"ConsoleOut(\"hello\")"};
    Parser parser(inputData);
    std::vector<std::unique_ptr<Command>> cmds = parser.parse();

    REQUIRE(expected[0]->getName() == cmds[0]->getName());

}

TEST_CASE("test parse invalid commands")
{
    std::vector<std::string> data = {"invalid()", "ConsoleOut(invalid, invalid, invalid)"};
    Parser parser(data);

    REQUIRE_THROWS(parser.parse()); // assert throws exception
}

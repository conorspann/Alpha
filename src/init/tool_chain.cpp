
#include "../../include/init/tool_chain.h"
#include "../../include/formatter/formatter.h"
#include "../../include/init/parser.h"
#include "../../include/init/preprocessor.h"
#include "../../include/runtime/interpreter.h"
#include "../../include/gui/window.h"
#include "../../include/error_codes.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <memory>
#include <utility>

int ToolChain::start(int argc, char * argv[])
{
    try
    {
        PreProcessor preProcessor;
        std::vector<std::pair<int, std::string>> rawData = preProcessor.includeFiles(argv[1]);

        Formatter formatter;
        std::vector<std::pair<int, std::string>> statements = formatter.removeBlankLines(rawData);
        std::vector<std::pair<int, std::vector<std::string>>> formattedLines = formatter.tokeniseLines(statements);

        Parser parser;
        std::vector<std::unique_ptr<Command>> commands = std::move(parser.parse(formattedLines));

        if (argc == 3) {
            std::string commandLangOutput;
            for (int commandNumber = 0; commandNumber < commands.size(); commandNumber++) {
                commandLangOutput += commands[commandNumber]->toString();
                commandLangOutput += ";";
            }

            std::ofstream outputFile(argv[2], std::ofstream::binary);
            outputFile << commandLangOutput;
            outputFile.close();

            return SUCCESS;
        }

        Interpreter interpreter(std::move(commands));
        interpreter.execute();
    }
    catch(const std::runtime_error & e)
    {
        std::cout << "Exception: " << e.what() << std::endl << "Exiting" << std::endl;
        SDL_Quit();

        return ERR_RUNTIME;
    }
    SDL_Quit();

    return SUCCESS;
}

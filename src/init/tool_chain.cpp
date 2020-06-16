
#include "../../include/init/tool_chain.h"
#include "../../include/init/file_loader.h"
#include "../../include/formatter/formatter.h"
#include "../../include/init/parser.h"
#include "../../include/init/preprocessor.h"
#include "../../include/runtime/interpreter.h"
#include "../../include/gui/window.h"
#include "../../include/error_codes.h"

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <memory>
#include <utility>

int ToolChain::start(char * argv[])
{
    try
    {
        PreProcessor preProcessor; /** TODO: implement include files */

        FileLoader loader;
        std::vector<std::pair<int, std::string>> rawData = loader.load(argv[1]);

        Formatter formatter;
        std::vector<std::pair<int, std::string>> statements = formatter.removeBlankLines(rawData);
        std::vector<std::pair<int, std::vector<std::string>>> formattedLines = formatter.tokeniseLines(statements);

        Parser parser;
        Interpreter interpreter(std::move(parser.parse(formattedLines)));
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

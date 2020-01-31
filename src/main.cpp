
#include "../include/init/loader.h"
#include "../include/formatter/formatter.h"
#include "../include/init/parser.h"
#include "../include/init/preprocessor.h"
#include "../include/runtime/interpreter.h"

#include <stdexcept>
#include <iostream>
#include <vector>
#include <memory>
#include <utility>

/** RELEASE ONLY */

int main(int argc, char ** argv)
{
    std::cout << "Alpha Interpreter v 0.1" << std::endl;
    if(argc != 2){
        std::cout << "Usage: alpha <filename>" << std::endl;
        return -1;
    }
    try
    {
        /**
            These calls could be grouped together in a different class
        */

        Loader loader(argv[1]);

        Formatter formatter;
        std::vector<std::string> statements = formatter.removeBlankLines(loader.getData());
        std::vector<std::vector<std::string>> formattedLines = formatter.formatLines(statements);

        PreProcessor preProcessor;
        std::vector<CommandData> customCommands = preProcessor.getCustomCommands(formattedLines);

        Parser parser;
        Interpreter interpreter(std::move(parser.parse(formattedLines, customCommands)));
        interpreter.execute();
    }
    catch(const std::runtime_error & e)
    {
        std::cout << "Exception: " << e.what() << std::endl << "Exiting" << std::endl;
        return -2;
    }
    return 0;
}

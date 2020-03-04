
#include <stdexcept>
#include <iostream>
#include <vector>
#include <memory>
#include <utility>

#include "../include/init/file_loader.h"
#include "../include/formatter/formatter.h"
#include "../include/init/parser.h"
#include "../include/init/preprocessor.h"
#include "../include/runtime/interpreter.h"
#include "../include/gui/window.h"

/** RELEASE ONLY */

int main(int argc, char * argv[])
{
    std::cout << "Alpha Interpreter v 0.1" << std::endl;
    if(argc != 2){
        std::cout << "Usage: alpha <filename>" << std::endl;
        return -1;
    }

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "Error: SDL could not be initialised" << std::endl;
        return -3;
    }

    try
    {
        /**
            These calls could be grouped together in a different class
        */


        PreProcessor preProcessor; /** TODO: implement include files */

        FileLoader loader;
        std::vector<std::pair<int, std::string>> rawData = loader.load(argv[1]);

        Formatter formatter;
        std::vector<std::pair<int, std::string>> statements = formatter.removeBlankLines(rawData);
        std::vector<std::pair<int, std::vector<std::string>>> formattedLines = formatter.formatLines(statements);

        Parser parser;
        Interpreter interpreter(std::move(parser.parse(formattedLines)));
        interpreter.execute();
    }
    catch(const std::runtime_error & e)
    {
        std::cout << "Exception: " << e.what() << std::endl << "Exiting" << std::endl;
        SDL_Quit();

        return -2;
    }
    SDL_Quit();

    return 0;
}

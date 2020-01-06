
#include "loader.h"
#include "parser.h"
#include "command.h"
#include "interpreter.h"

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
        Loader loader(argv[1]);
        Parser parser(loader.getData());
        Interpreter interpreter(std::move(parser.parse()));
        interpreter.execute();
    }
    catch(const std::runtime_error & e )
    {
        std::cout << "Exception: " << e.what() << std::endl << "Exiting" << std::endl;
        return -2;
    }
    return 0;
}

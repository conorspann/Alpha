
#include "../../include/init/initialiser.h"

#include <iostream>

#include <SDL.h>

bool Initialiser::initialiseCmdArgs(int argc)
{
    std::cout << "AlphaParser v 0.1" << std::endl;
    if (argc != 2 && argc != 3) {
        std::cout << "Usage: alphaparser <inputFilename> [outputFilename]" << std::endl;

        return false;
    }

    return true;
}


bool Initialiser::initialiseSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Error: SDL could not be initialised" << std::endl;
        return false;
    }

    return true;
}

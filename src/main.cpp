

#include "../include/init/initialiser.h"
#include "../include/init/tool_chain.h"
#include "../include/error_codes.h"

/** RELEASE ONLY */

int main(int argc, char * argv[])
{
    Initialiser initialiser;

    if (!initialiser.initialiseCmdArgs(argc)) {
        return ERR_CL_ARGS;
    }

    if (!initialiser.initialiseSDL()) {
        return ERR_SDL_INIT;
    }

    ToolChain toolchain;

    return toolchain.start(argv);
}

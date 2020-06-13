

#include "../include/init/initialiser.h"
#include "../include/init/tool_chain.h"

/** RELEASE ONLY */

int main(int argc, char * argv[])
{
    Initialiser initialiser;

    if (!initialiser.initialiseCmdArgs(argc)) {
        return -1;
    }

    if (!initialiser.initialiseSDL()) {
        return -3;
    }

    ToolChain toolchain;

    return toolchain.start(argv);
}

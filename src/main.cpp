#include <iostream>
#include "ProjectConfig.h"

int main(int argc, char** argv) {
    std::cout << argv[0] << " VERSION " << GraphDB_VERSION_MAJOR << "." <<
        GraphDB_VERSION_MINOR << std::endl;

    return 0;
}
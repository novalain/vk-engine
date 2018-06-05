#include "core/engine.h"
#include <iostream>

int main() {
    bl::Engine e; // Create instance of engine with all dependencies
	//e.set_title("Test Deferred");s
	//e.set_renderer

    e.Run();
	
    std::cin.get();
    return 0;
}
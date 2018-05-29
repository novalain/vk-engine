#include "engine.h"

Engine::Engine() {
    // mRenderer
    // mUpdater
}

Engine::~Engine() {

}

Engine::run() {
    std::cout << "running engine\n";
    while (true) {
        m_moduleRegister->update();
        renderer->render();
    }
}
#include "moduleregister.h"
#include "glfwdisplay.h"

ModuleRegister::ModuleRegister() {
    // mRenderer
    // mUpdater
    RegisterModule(std::make_unique<DisplayGlfw>());
    RegisterModule(std::make_unique<RendererVk>());
}

ModuleRegister::~ModuleRegister() {

}

ModuleRegister::run() {
    std::cout << "running ModuleRegister\n";
    while (true) {
        m_moduleRegister->update();
        renderer->render();
    }
}
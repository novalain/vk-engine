#include "moduleregister.h"
#include "glfwdisplay.h"

ModuleRegister::ModuleRegister() {
    RegisterModule({std::make_unique<DisplayGlfw>()});
    //RegisterModule(std::make_unique<RendererVk>());
}

ModuleRegister::~ModuleRegister() {

}

ModuleRegister::RegisterModule(const&& ModulePair module_pair) {
    _modules.emplace(std::move(module_pair));
}

ModuleRegister::run() {
    std::cout << "running ModuleRegister\n";
    while (true) {
        m_moduleRegister->update();
        renderer->render();
    }
}
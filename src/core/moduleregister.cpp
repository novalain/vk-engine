#include "core/moduleregister.h"
#include "display/displayglfw.h"

namespace bl {

ModuleRegister::ModuleRegister() {
    RegisterModule({"Display", UPDATE_ALWAYS, std::make_unique<DisplayGlfw>()});
}

void ModuleRegister::RegisterModule(ModuleData&& module) {
	m_modules.push_back(std::move(module));
}

void ModuleRegister::Update() {
for (const auto& module_data : m_modules) {
        module_data.module->Update();
   }
}

} // namespace bl
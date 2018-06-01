#include "core/moduleregister.h"
#include "display/displayglfw.h"

namespace bl {

ModuleRegister::ModuleRegister() {
	RegisterModule({"Display", UPDATE_ALWAYS});
}

void ModuleRegister::RegisterModule(const ModuleData&& module) {
	m_modules.emplace_back(std::move(module));
}

void ModuleRegister::Update() {
   // for (const auto &module : *m_modules) {
   //     module.second.second->update();
   // }
}

} // namespace bl
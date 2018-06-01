#pragma once
#include <memory>
#include <string>
#include "core/imodule.h"
#include <vector>

namespace bl {

struct ModuleData {
	std::string name;
	ModuleUpdate update_freq;
//	std::unique_ptr<IModule> module;
};

class ModuleRegister {
typedef std::pair<std::string, std::unique_ptr<IModule>> ModulePair;

public:
	ModuleRegister();

	void RegisterModule(const ModuleData&& module);
	void Update();
private:
	std::vector<ModuleData> m_modules;
};

} // namespace bl

#pragma once

namespace bl {

class ModuleRegister {
typedef std::pair<std::string, std::unique_ptr<IModule>> ModulePair;

public:
	ModuleRegister();
	~ModuleRegister();

	RegisterModule(const& ModulePair module_pair);
private:
	std::multimap<float, ModulePair> _modules;
};

} // namespace bl

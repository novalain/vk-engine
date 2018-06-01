#pragma once

namespace bl {

enum ModuleUpdate {
	UPDATE_ALWAYS = 0,
	UPDATE_PRE = 1,
	UPDATE_NORMAL = 2,
	UPDATE_POST = 3,
	UPDATE_RENDER = 4
};

class IModule {
public:
	virtual ~IModule() = default;

	virtual void Update() = 0;
};

} // namespace bl


#pragma once

#include "core/moduleregister.h"
#include "renderer/irenderer.h"

namespace bl {

namespace ir {
	class IRenderer;
}

class Engine {
public:
	Engine();
	void Run();

private:
	ModuleRegister m_moduleRegister;
	std::unique_ptr<ir::IRenderer> m_renderer;
};

} // namespace bl

#pragma once

#include "core/moduleregister.h"
#include "renderer/irenderer.h"
#include "display/idisplay.h"

namespace bl {

namespace ir {
	class IRenderer;
}

class Engine {
public:
	Engine();
	void Run();

private:
	std::unique_ptr<ModuleRegister> m_module_register;
	std::unique_ptr<IDisplay> m_display;
	std::unique_ptr<ir::IRenderer> m_renderer;
};

} // namespace bl

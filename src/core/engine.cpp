#include "engine.h"
#include <iostream>

#include "renderer/vulkan/renderervk.h"
#include "display/displayglfw.h"

namespace bl {

Engine::Engine() {
    std::cout << "Setting up Engine ... \n";

	m_display = std::make_unique<DisplayGlfw>();
	m_renderer = std::make_unique<ir::RendererVk>(m_display.getRequiredExtensions());
	m_display.createSurface(m_renderer.getInstance());

	// Set up renderer
    //m_renderer = std::make_unique<ir::RendererVk>();
	// Set up display
}

void Engine::Run() {
    std::cout << "Blazing Engine Running ... \n";
}

} // namespace bl
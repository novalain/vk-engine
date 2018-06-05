#include "engine.h"
#include <iostream>

#include "renderer/vulkan/renderervk.h"

namespace bl {

Engine::Engine() {
    std::cout << "Setting up Engine ... \n";
    m_renderer = std::make_unique<ir::RendererVk>();
}

void Engine::Run() {
    std::cout << "Blazing Engine Running ... \n";
}

} // namespace bl
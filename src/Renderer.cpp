#include "Renderer.h"

#include <cstdlib>
#include <assert.h>

Renderer::Renderer() {
	_initInstance();
}

Renderer::~Renderer() {
	_deinitInstance();
}

void Renderer::_initInstance() {
	VkInstanceCreateInfo instance_create_info{};
	instance_create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;

	auto err = vkCreateInstance(&instance_create_info, nullptr, &mInstance);
	if (err != VK_SUCCESS) {
		assert(1 && "Vulkan ERROR: Create instance failed!");
		std::exit(-1);
	}
}

void Renderer::_deinitInstance() {
	vkDestroyInstance(mInstance, nullptr);
	mInstance = nullptr;
}
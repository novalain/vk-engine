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
	// Set up application info
	VkApplicationInfo application_info {};
	application_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	application_info.apiVersion = VK_API_VERSION_1_1;
	application_info.applicationVersion = VK_MAKE_VERSION(0, 1, 0);
	application_info.pApplicationName = "Vulkan Engine";

	VkInstanceCreateInfo instance_create_info{};
	instance_create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	instance_create_info.pApplicationInfo = &application_info;

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
#pragma once

#include <vulkan/vulkan.h>

class Renderer {
public:
	Renderer();
	~Renderer();

private:
	void _initInstance();
	void _deinitInstance();

	void _initDevice();
	void _deinitDevice();

	VkInstance mInstance = nullptr;
};

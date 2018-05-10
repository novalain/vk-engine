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
	VkDevice mDevice = nullptr;
	VkPhysicalDevice mGpu = nullptr;
	VkPhysicalDeviceProperties mGpuProperties;

	uint32_t mGraphicsFamilyIndex;
};

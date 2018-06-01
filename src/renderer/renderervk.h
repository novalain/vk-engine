#pragma once

#include <vulkan/vulkan.h>
#include <vector>
#include "irenderer.h"

namespace bl {

class Renderer : public IRenderer {
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

	std::vector<const char*> mInstanceLayers;
	std::vector<const char*> mInstanceExtensionss;

	// Deprecated!!
	std::vector<const char*> mDeviceLayers;
	std::vector<const char*> mDeviceExtensions;
};

}

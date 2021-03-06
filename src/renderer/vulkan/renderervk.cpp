#include "renderervk.h"
#include "renderer/vulkan/rendercontextvk.h"

namespace bl::ir {
RendererVk::RendererVk() {
    m_rendercontext = std::make_unique<RenderContextVk>();
}

RendererVk::~RendererVk() {
}
    //
    //Renderer::Renderer() {
    //	_initInstance();
    //	_initDevice();
    //}
    //
    //Renderer::~Renderer() { 
    //	_deinitDevice();
    //	_deinitInstance();
    //}
    //
    //void Renderer::_initInstance() {
    //	// Set up application info
    //	VkApplicationInfo application_info {};
    //	application_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    //	//application_info.apiVersion = VK_MAKE_VERSION(1, 2, 20);
    //	application_info.applicationVersion = VK_MAKE_VERSION(0, 1, 0);
    //	application_info.pApplicationName = "Vulkan Engine";
    //
    //	VkInstanceCreateInfo instance_create_info{};
    //	instance_create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    //	instance_create_info.pApplicationInfo = &application_info;
    //	instance_create_info.enabledLayerCount = mInstanceLayers.size();
    //	instance_create_info.ppEnabledLayerNames = mInstanceLayers.data();
    //
    //	auto err = vkCreateInstance(&instance_create_info, nullptr, &mInstance);
    //	if (err != VK_SUCCESS) {
    //		assert(1 && "Vulkan ERROR: Create instance failed!");
    //		std::exit(-1);
    //	}
    //}
    //
    //void Renderer::_deinitInstance() {
    //	vkDestroyInstance(mInstance, nullptr);
    //	mInstance = nullptr;
    //}
    //
    //void Renderer::_initDevice() {
    //	{
    //		uint32_t gpu_count;
    //		vkEnumeratePhysicalDevices(mInstance, &gpu_count, nullptr);
    //		std::vector<VkPhysicalDevice> gpu_list(gpu_count);
    //		vkEnumeratePhysicalDevices(mInstance, &gpu_count, gpu_list.data());
    //		mGpu = gpu_list[0]; // Might not be the best gpu
    //		vkGetPhysicalDeviceProperties(mGpu, &mGpuProperties);
    //	}
    //
    //	// Figure out which family to use. What does our gpu support?
    //	{
    //		uint32_t family_count;
    //		vkGetPhysicalDeviceQueueFamilyProperties(mGpu, &family_count, nullptr);
    //		std::vector<VkQueueFamilyProperties> family_properties_list(family_count);
    //		vkGetPhysicalDeviceQueueFamilyProperties(mGpu, &family_count, family_properties_list.data());
    //
    //		// Check which one supports traffics bit
    //		auto found = false;
    //		for (auto i = 0; i < family_count; ++i) {
    //			if (family_properties_list[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) {
    //				found = true;
    //				mGraphicsFamilyIndex = i;
    //			}
    //		}
    //		if (!found) {
    //			assert(1 && "Vulkan ERROR: Queue family supporting graphics not found!");
    //			std::exit(-1);
    //		}
    //	}
    //
    //	// Validation layers
    //	{
    //		uint32_t layer_count = 0;
    //		vkEnumerateInstanceLayerProperties(&layer_count, nullptr);
    //		std::vector<VkLayerProperties> layer_property_list(layer_count);
    //		vkEnumerateInstanceLayerProperties(&layer_count, layer_property_list.data());
    //		std::cout << "Instance Layers: \n";
    //		for (auto &i : layer_property_list) {
    //			std::cout << " " << i.layerName << "\t\t | " << i.description << std::endl;
    //		}
    //		std::cout << std::endl;
    //	}
    //
    //	// Device layers - DEPRECATED!!
    //	{
    //		uint32_t layer_count = 0;
    //		vkEnumerateDeviceLayerProperties(mGpu, &layer_count, nullptr);
    //		std::vector<VkLayerProperties> layer_property_list(layer_count);
    //		vkEnumerateDeviceLayerProperties(mGpu, &layer_count, layer_property_list.data());
    //		std::cout << "Device Layers: \n";
    //		for (auto &i : layer_property_list) {
    //			std::cout << " " << i.layerName << "\t\t | " << i.description << std::endl;
    //		}
    //		std::cout << std::endl;
    //	}
    //
    //	// Type of work that gpu will do
    //	//float queue_priorities[] = { 1.0f };
    //	float queuePriority = 1.0f;
    //	VkDeviceQueueCreateInfo device_queue_create_info {};
    //	device_queue_create_info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    //	device_queue_create_info.queueFamilyIndex = mGraphicsFamilyIndex;
    //	device_queue_create_info.queueCount = 1; // How many queues in this family
    //	device_queue_create_info.pQueuePriorities = &queuePriority; // Which one takes most priority if both has work
    //
    //	VkDeviceCreateInfo device_create_info = {};
    //	device_create_info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    //	device_create_info.queueCreateInfoCount = 1; //One queue create info
    //	device_create_info.pQueueCreateInfos = &device_queue_create_info;
    //	VkPhysicalDeviceFeatures device_features = {};
    //	device_create_info.pEnabledFeatures = &device_features;
    //
    //	const auto err = vkCreateDevice(mGpu, &device_create_info, nullptr, &mDevice);
    //	if (err != VK_SUCCESS) {
    //		assert(1 && "Vulkan ERROR: create device failed!");
    //		std::exit(-1);
    //	}
    //}
    //
    //void Renderer::_deinitDevice() {
    //	vkDestroyDevice(mDevice, nullptr);
    //	mDevice = nullptr;
    //}

}
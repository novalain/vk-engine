#include "rendercontextvk.h"

#include <vulkan/vulkan.h>
#include <vector>
#include <string>

#include <GLFW/glfw3.h>

namespace bl::ir {

namespace {
	void _LogLayers(const std::vector<VkLayerProperties> &layer_props, const std::string &type, const bool &show_desc) {
		printf("** Available Layers For: '%s' **\n", type.c_str());
		for (const auto layer : layer_props) {
			if (show_desc) {
				printf("\n    %s   | %s, \n", layer.layerName, layer.description);
			} else {
				printf("%s, \n", layer.layerName);
			}
		}
	}

	const std::vector<const char*> VALIDATION_LAYERS = {
		"VK_LAYER_LUNARG_standard_validation"
	};

	const std::vector<const char *> DEVICE_EXTENSIONS = {
		VK_KHR_SWAPCHAIN_EXTENSION_NAME
	};
}

RenderContextVk::RenderContextVk() :
	m_use_validation_layers(false) {

    _SetupLayers();
	_SetupExtensions();
}

void RenderContextVk::_SetupLayers() {
    uint32_t instance_layer_property_count;
    vkEnumerateInstanceLayerProperties(&instance_layer_property_count, nullptr);
    std::vector<VkLayerProperties> instance_layer_properties(instance_layer_property_count);
    vkEnumerateInstanceLayerProperties(&instance_layer_property_count, instance_layer_properties.data());

    _LogLayers(instance_layer_properties, "Instance", false);

    // Sets up the layers.
    if (m_use_validation_layers) {
		for (const auto& layer_name : VALIDATION_LAYERS) {
			bool layer_found = false;

			for (const auto layer_props : instance_layer_properties) {
				if (strcmp(layer_name, layer_props.layerName) == 0) {
					layer_found = true;
					break;
				}
			}

			if (!layer_found) {
				fprintf(stderr, "Vulkan validation layer not found: '%s'\n", layer_name);
			}

			m_instance_layer_list.push_back(layer_name);
		}
    }

	for (const auto& layerName : DEVICE_EXTENSIONS) {
		m_device_extension_list.push_back(layerName);
	}

    // for (auto layerName : DEVICE_EXTENSIONS)
    // {
    //     m_deviceExtensionList.push_back(layerName);
    // }
}

void RenderContextVk::_SetupExtensions() {
	unsigned int glfw_extension_count = 0;
	const char** glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);

	for (uint32_t i = 0; i < glfw_extension_count; i++) {
		m_instance_extension_list.push_back(glfw_extensions[i]);
	}

	if (m_use_validation_layers) {
		m_instance_extension_list.push_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);
	}
}

} // namespace bl::ir
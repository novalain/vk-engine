#include "rendercontextvk.h"

#include <vulkan/vulkan.h>
#include <vector>
#include <string>

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
}

RenderContextVk::RenderContextVk() {
    _SetupLayers();
}

void RenderContextVk::_SetupLayers() {
    uint32_t instance_layer_property_count;
    vkEnumerateInstanceLayerProperties(&instance_layer_property_count, nullptr);
    std::vector<VkLayerProperties> instance_layer_properties(instance_layer_property_count);
    vkEnumerateInstanceLayerProperties(&instance_layer_property_count, instance_layer_properties.data());

    _LogLayers(instance_layer_properties, "Instance", false);

    // // Sets up the layers.
    // if (m_use_validation_layers) {
    //     for (auto layerName : VALIDATION_LAYERS) {
    //         bool layerFound = false;

    //         for (auto layerProperties : instanceLayerProperties)
    //         {
    //             if (strcmp(layerName, layerProperties.layerName) == 0)
    //             {
    //                 layerFound = true;
    //                 break;
    //             }
    //         }

    //         if (!layerFound)
    //         {
    //             fprintf(stderr, "Vulkan validation layer not found: '%s'\n", layerName);
    //         }

    //         m_instanceLayerList.push_back(layerName);
    //     }
    // }

    // for (auto layerName : DEVICE_EXTENSIONS)
    // {
    //     m_deviceExtensionList.push_back(layerName);
    // }
}

} // namespace bl::ir
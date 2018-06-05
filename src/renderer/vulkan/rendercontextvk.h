#pragma once

#include <vector>

namespace bl::ir {

class RenderContextVk {
public:
    RenderContextVk();

private:
    void _SetupLayers();
	void _SetupExtensions();

	bool m_use_validation_layers;

	std::vector<const char*> m_instance_layer_list;
	std::vector<const char*> m_device_extension_list;
	std::vector<const char*> m_instance_extension_list;

};

} // namespace bl::ir

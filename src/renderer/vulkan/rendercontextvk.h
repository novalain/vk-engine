#pragma once

namespace bl::ir {

class RenderContextVk {
public:
    RenderContextVk();

private:
    void _SetupLayers();
};

} // namespace bl::ir

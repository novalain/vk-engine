#pragma once

namespace bl::ir {

class IRenderer {
public:
    virtual ~IRenderer() = default;
    virtual bool CreateVertexBuffer() = 0;
    virtual bool CreatePipelineState() = 0;
};

}

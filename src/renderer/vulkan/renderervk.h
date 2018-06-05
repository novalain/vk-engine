#pragma once

#include <memory>
#include "renderer/irenderer.h"

namespace bl::ir {

class RenderContextVk;
class RendererVk : public IRenderer {
public:
	RendererVk();
	~RendererVk();

	virtual bool CreateVertexBuffer() final { return true; }
	virtual bool CreatePipelineState() final { return true; }
private:
	std::unique_ptr<RenderContextVk> m_rendercontext;
};

}

#pragma once

#include "core/imodule.h"

namespace bl {
	
class DisplayGlfw : public IModule {

public:
	DisplayGlfw();
	virtual void Update() override;
};

} // namespace bl

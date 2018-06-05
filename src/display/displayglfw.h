#pragma once

#include "core/imodule.h"
#include <string>

struct GLFWwindow;

namespace bl {
	
class DisplayGlfw : public IModule {
public:
	DisplayGlfw();
	~DisplayGlfw(); 
	void _Initialize();

	virtual void Update() override;
private:
	bool m_fullscreen;
	GLFWwindow *m_window;
	std::string m_title;
	uint32_t m_window_width;
	uint32_t m_window_height;
};

} // namespace bl

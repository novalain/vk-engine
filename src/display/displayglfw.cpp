#include "displayglfw.h"

#include <GLFW/glfw3.h>
#include <iostream>

namespace {
	void CallbackError(int error, const char *description) {

		//Display::ErrorGlfw(error);
		//fprintf(stderr, "GLFW error: %s, %i\n", description, error);
	}
}

namespace bl {

	DisplayGlfw::DisplayGlfw() : 
		m_window_width(1080),
		m_window_height(720),
		m_title("Loading ..."),
		m_fullscreen(false)
	{
		_Initialize();
	}

	DisplayGlfw::~DisplayGlfw() {
		// Free the window callbacks and destroy the window.
		// Requires vulkan context to be destroyed first?
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}

	void DisplayGlfw::_Initialize() {
		glfwSetErrorCallback(CallbackError);

		// Initialize the GLFW library.
		if (!glfwInit()) {
			fprintf(stderr, "GLFW error: Failed to initialize!\n");
			//throw std::runtime_error("GLFW runtime error.");
		}

		// todo: check api support
		// if (!glfwVulkanSupported()) {
		// 	fprintf(stderr, "GLFW error: Failed to find Vulkan support!\n");
		// 	//throw std::runtime_error("GLFW runtime error.");
		// }

		// Configures the window.
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);  // The window will stay hidden until after creation.
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE); // The window will be resizable depending on if it's fullscreen.
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // Disable context creation.

		// For new GLFW, and macOS.
		glfwWindowHint(GLFW_STENCIL_BITS, 8);	// Fixes 16 bit stencil bits in macOS.
		glfwWindowHint(GLFW_STEREO, GLFW_FALSE); // No stereo view!

		// Get the resolution of the primary monitor.
		GLFWmonitor *monitor = glfwGetPrimaryMonitor();
		const GLFWvidmode *videoMode = glfwGetVideoMode(monitor);

		//if (m_fullscreen) {
		//	m_fullscreenWidth = videoMode->width;
		//	m_fullscreenHeight = videoMode->height;
		//	m_aspectRatio = static_cast<float>(videoMode->width) / static_cast<float>(videoMode->height);
		//}

		// Create a windowed mode window with no context
		//m_window = glfwCreateWindow(m_fullscreen ? m_fullscreenWidth : m_windowWidth, m_fullscreen ? m_fullscreenHeight : m_windowHeight, m_title.c_str(), m_fullscreen ? monitor : nullptr, nullptr);
		m_window = glfwCreateWindow(m_window_width, m_window_height, m_title.c_str(), nullptr, nullptr);

		// Gets any window errors.
		if (m_window == nullptr) {
			glfwTerminate();
			//throw std::runtime_error("Filed to create the GLFW window!");
		}

		// Centre the window position.
		//m_windowPosX = (videoMode->width - m_windowWidth) / 2;
		//m_windowPosY = (videoMode->height - m_windowHeight) / 2;
		//glfwSetWindowPos(m_window, m_windowPosX, m_windowPosY);

		// Shows the glfw window.
		glfwShowWindow(m_window);

		// Sets the displays callbacks.
		//glfwSetWindowUserPointer(m_window, this);
		//glfwSetWindowCloseCallback(m_window, CallbackClose);
		//glfwSetWindowFocusCallback(m_window, CallbackFocus);
		//glfwSetWindowPosCallback(m_window, CallbackPosition);
		//glfwSetWindowSizeCallback(m_window, CallbackSize);
		//glfwSetFramebufferSizeCallback(m_window, CallbackFrame);
		//glfwSetWindowIconifyCallback(m_window, CallbackIconify);
	}

	void DisplayGlfw::Update() {
		std::cout << "Updating display glfw \n";
		glfwPollEvents();
	}

} // namespace bl
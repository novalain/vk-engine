project(vk-engine)
cmake_minimum_required(VERSION 3.10)

# Vulkan SDK has to be installed
find_package(Vulkan REQUIRED)

# Set compilation flags
if(MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else(MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")
endif(MSVC)

# Glfw stuff
option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(ext/glfw)

# Generate lists of source files
file(GLOB PROJECT_HEADERS include/*.h)
file(GLOB PROJECT_SOURCES src/*.cpp)
file(GLOB PROJECT_SHADERS shaders/*.comp shaders/*.frag shaders/*.geom shaders/*.vert)

# IDE groups
source_group("Headers" FILES ${PROJECT_HEADERS})
source_group("Shaders" FILES ${PROJECT_SHADERS})
source_group("Sources" FILES ${PROJECT_SOURCES})

# Glfw needs to know about vulkan
add_definitions(-DGLFW_INCLUDE_VULKAN)

# Add executable and link
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
include_directories(${Vulkan_INCLUDE_DIRS}  
					ext/glm
					ext/glfw/include)
target_link_libraries (${PROJECT_NAME} ${Vulkan_LIBRARIES} glfw)

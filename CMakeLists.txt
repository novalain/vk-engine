project(vk-engine)
cmake_minimum_required(VERSION 3.9)

# Vulkan SDK has to be installed
find_package(Vulkan REQUIRED)

# Set compilation flags
if(MSVC)
	set_property(GLOBAL PROPERTY USE_FOLDERS ON)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else(MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++17")
endif(MSVC)

# Glfw stuff
option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(ext/glfw)

# Generate lists of source files
file(GLOB_RECURSE PROJECT_HEADERS src/*.h)
file(GLOB_RECURSE PROJECT_SOURCES src/*.cpp)

#file(GLOB_RECURSE PROJECT_CORE src/core/*.cpp src/core/*.h)
#file(GLOB_RECURSE PROJECT_DISPLAY src/display/*cpp src/display/*.h)
#file(GLOB_RECURSE PROJECT_RENDERER src/renderer/*.cpp src/renderer/*.h)
#file(GLOB_RECURSE PROJECT_EXAMPLES src/examples/*.cpp src/examples/*.h)
#file(GLOB PROJECT_SHADERS shaders/*.comp shaders/*.frag shaders/*.geom shaders/*.vert)

# IDE groups
#source_group("headers" FILES ${PROJECT_HEADERS})
#source_group("core" FILES ${PROJECT_CORE})
#source_group("display" FILES ${PROJECT_DISPLAY})
#source_group("renderer" FILES ${PROJECT_RENDERER})
#source_group("examples" FILES ${PROJECT_EXAMPLES})

#source_group("headers" FILES ${PROJECT_HEADERS})
#source_group("sources" FILES ${PROJECT_SOURCES})

# Glfw needs to know about vulkan
add_definitions(-DGLFW_INCLUDE_VULKAN)

# Choose the right start up project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

# Add executable and link
#add_executable(${PROJECT_NAME} ${PROJECT_CORE} ${PROJECT_DISPLAY} ${PROJECT_RENDERER} ${PROJECT_EXAMPLES})

add_executable(${PROJECT_NAME} ${PROJECT_HEADERS} ${PROJECT_SOURCES})


include_directories(${Vulkan_INCLUDE_DIRS}
					src/
					ext/glm
					ext/glfw/include)
target_link_libraries (${PROJECT_NAME} ${Vulkan_LIBRARIES} glfw)

#set_target_properties(${PROJECT_NAME} PROPERTIES
#   RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

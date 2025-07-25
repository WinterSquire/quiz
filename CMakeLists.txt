cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(./dep/libmcc)

project(imgui)

set(${PROJECT_NAME}_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dep/imgui)

set(${PROJECT_NAME}_SRC 
	${${PROJECT_NAME}_DIR}/imgui.cpp
	${${PROJECT_NAME}_DIR}/imgui_demo.cpp
	${${PROJECT_NAME}_DIR}/imgui_draw.cpp
	${${PROJECT_NAME}_DIR}/imgui_tables.cpp
	${${PROJECT_NAME}_DIR}/imgui_widgets.cpp
	${${PROJECT_NAME}_DIR}/backends/imgui_impl_win32.cpp
	${${PROJECT_NAME}_DIR}/backends/imgui_impl_dx11.cpp
)

add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}_SRC})

target_include_directories(${PROJECT_NAME} PUBLIC ${${PROJECT_NAME}_DIR})

project(quiz)

file(GLOB_RECURSE ${PROJECT_NAME}_SRC ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SRC})

target_link_libraries(${PROJECT_NAME} PRIVATE imgui libmcc d3d11)


#cmake ../ -G "Visual Studio 16 2019" -DCOMMON_LIBS="C:"
#cmake ../ -G "Visual Studio 16 2019" -DCOMMON_LIBS="C:\Users\Garrett\Documents"
cmake_minimum_required(VERSION 2.8)
PROJECT(base_project)
message(STATUS ${COMMON_LIBS})
set(OpenCV_DIR ${COMMON_LIBS}/opencv/build)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


set(CODE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/code)
include_directories(${CODE_DIR})
set(PROJECT_FILES
    ${CODE_DIR}/main.cpp
    ${CODE_DIR}/DrawImages.cpp
	${CODE_DIR}/DrawImages.h
)
add_executable(base_project ${PROJECT_FILES})
target_link_libraries(base_project ${OpenCV_LIBS})






message(STATUS ${CODE_DIR})
message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Release)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/include
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Release)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/include
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug)
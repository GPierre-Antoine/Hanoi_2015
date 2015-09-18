cmake_minimum_required(VERSION 3.3)
project(Hanoi_2015)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lGL ")

#########################################################
# FIND OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if (NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif (NOT OPENGL_FOUND)

#########################################################
# Include Files
#########################################################
add_executable(Hanoi_2015 main.cpp gl3.h)

########################################################
# Linking & stuff
#########################################################

target_link_libraries(Hanoi_2015 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
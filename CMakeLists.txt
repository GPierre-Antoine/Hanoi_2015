cmake_minimum_required(VERSION 3.3)
project(Hanoi_2015)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lGL -Wall ")

SET(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

#########################################################
# FIND OPENGL
#########################################################
#find_package(OpenGL REQUIRED)
#include_directories(${OpenGL_INCLUDE_DIRS})
#link_directories(${OpenGL_LIBRARY_DIRS})
#add_definitions(${OpenGL_DEFINITIONS})
#if (NOT OPENGL_FOUND)
#    message(ERROR " OPENGL not found!")
#endif (NOT OPENGL_FOUND)
#
#
#set(SDL2_INCLUDE_DIR /usr/include/SDL2)
#set(SDL2_LIBRARY /usr/lib/libSDL2.so)
#
#include_directories(${SDL2_INCLUDE_DIRS})
#link_directories(${SDL2_LIBRARY})



#########################################################
# Include Files
#########################################################



set(SOURCE_FILES cepepe/HanoiCube.cpp cepepe/HanoiPoint.cpp cepepe/HanoiMatrix.cpp include/HanoiMatrix.h)

add_executable(Hanoi_2015 main.cpp ${SOURCE_FILES})

########################################################
# Linking & stuff
#########################################################

target_link_libraries(Hanoi_2015 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
cmake_minimum_required(VERSION 2.8.9)

#set the project name
project (plate)

#Set the compiler
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)
set( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set( LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#Set ccache (for speeding up)
find_program(CCACHE_FOUND ccache) 
if(CCACHE_FOUND) 
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache) 
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache) 
endif(CCACHE_FOUND) 
set (CMAKE_CXX_FLAGS "-DPCL_ONLY_CORE_POINT_TYPES=ON -DNO_EXPLICIT_INSTANTIATIONS") 

############### Dependencies #######################

#Add opencv cmake .config path
set (OpenCV_DIR opt/opencv/release)

#Find opencv libs
find_package(OpenCV 4.5.1 REQUIRED)

############### My Files #########################

#Bring the headers
include_directories(${PROJECT_SOURCE_DIR}/include)

#Bring the source files
add_subdirectory(${PROJECT_SOURCE_DIR}/src/lib)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/demo)






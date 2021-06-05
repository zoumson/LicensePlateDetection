#cmake_minimum_required(VERSION 2.8.9)

#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_BUILD_TYPE Release)

#Set the executable name
#set(EXE main)
#set(LIB plate)
#set(PROJECT_LINK_LIB libplate.so)
#project (${EXE})

#Bring the custom libraries
#link_directories( lib)


#Bring the headers
#include_directories(include)

#Bring the sources
file(GLOB SOURCES_PLATE ${PROJECT_SOURCE_DIR}/src/plate/*.cpp)
#file(GLOB SOURCES_MAIN "src/main/*.cpp")


#Add opencv cmake .config path
#set (OpenCV_DIR opt/opencv/release)

#Find opencv libs
#find_package(OpenCV REQUIRED)

#Generate library
add_library(plate SHARED ${SOURCES_PLATE})

#Add other libraries used to build the main library
target_link_libraries(plate PRIVATE ${OpenCV_LIBS})

#Set an installation path, type "sudo make install" to apply
install(TARGETS plate DESTINATION /user/lib)

#Build the executable
#add_executable(${EXE} ${SOURCES_MAIN})

#Link the libraries 
#target_link_libraries(${EXE} ${PROJECT_LINK_LIB} ${OpenCV_LIBS})


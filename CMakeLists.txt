cmake_minimum_required(VERSION 2.8.9)

set(CMAKE_CXX_STANDARD 17)

#Set the executable name
set(EXE plate)

project (${EXE})

#Bring the custom libraries
link_directories( lib)


#Bring the headers
include_directories(include)

#Bring the sources
file(GLOB SOURCES "src/*.cpp")

#Add opencv cmake .config path
set (OpenCV_DIR opt/opencv/release)

#Find opencv libs
find_package(OpenCV REQUIRED)

#Build the executable
add_executable(${EXE} ${SOURCES})

#Link the libraries 
target_link_libraries(${EXE} ${OpenCV_LIBS})


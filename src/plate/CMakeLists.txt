#Bring the sources
file(GLOB SOURCES_PLATE ${PROJECT_SOURCE_DIR}/src/plate/*.cpp)

#Generate library
add_library(plate SHARED ${SOURCES_PLATE})

#Add other libraries used to build the main library
target_link_libraries(plate PRIVATE ${OpenCV_LIBS})

#Set an installation path, type "sudo make install" to apply
install(TARGETS plate DESTINATION /user/lib)


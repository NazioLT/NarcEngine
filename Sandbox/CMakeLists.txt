message(STATUS "Building Sandbox")

#----------------
#----- MAIN -----
#----------------

set(NARC_ENGINE_LIB_LIST "NarcEngine")

# Gather list of header and source files for compilation
file(GLOB_RECURSE CPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)

link_directories(${CMAKE_BINARY_DIR}/NarcEngine/${CONFIGURATION})

add_executable(${SANDBOX} src/TestEngine.cpp)

include_directories(${CMAKE_SOURCE_DIR}/NarcEngine/src/)

target_link_libraries( ${SANDBOX} PRIVATE ${NARC_ENGINE_LIB_LIST} )
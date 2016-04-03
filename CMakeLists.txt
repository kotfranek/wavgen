# CMake minimum version dependency
cmake_minimum_required( VERSION 3.0.0 FATAL_ERROR )

if( DEFINED ENV{TCLAP_HOME} )
    message( "TCLAP_HOME variable set to $ENV{TCLAP_HOME}" )
else()
    message( FATAL_ERROR "TCLAP_HOME variable is required!" )
endif()

# Project name
project( "wavgen" )

# Compiler and linker flags
set( CPP_COMPILE_FLAGS "-g -Wall -std=c++11" )
set( CPP_LINK_FLAGS "-oS" )

# Header files locations
include_directories( 
    include 
    $ENV{TCLAP_HOME}/include
)

# Main project library
add_library( wavgen-lib STATIC
    src/audio/WaveParameters.cpp
    src/audio/PcmSample.cpp
    src/audio/PcmGenerator.cpp
    src/audio/SineGenerator.cpp
    src/audio/SawToothGenerator.cpp
    src/audio/TriangleGenerator.cpp
    src/audio/SquareGenerator.cpp
    src/audio/utils.cpp
    src/audio/GeneratorFactory.cpp
)

# Demo application: sources
add_executable( wavgen
    src/main.cpp
)

# Demo application: required libraries
target_link_libraries( wavgen
    wavgen-lib
)

# Set the compiler and linker flags for particular targets
set_target_properties( wavgen-lib PROPERTIES COMPILE_FLAGS ${CPP_COMPILE_FLAGS} )
set_target_properties( wavgen PROPERTIES COMPILE_FLAGS ${CPP_COMPILE_FLAGS} )
set_target_properties( wavgen PROPERTIES LINK_FLAGS ${CPP_LINK_FLAGS} )

# Target install
install( TARGETS wavgen DESTINATION bin )
install( TARGETS wavgen-lib DESTINATION lib )
install( FILES 
    include/audio/types.h 
    include/audio/PcmSample.h 
    DESTINATION include/${CMAKE_PROJECT_NAME}/audio
    
)

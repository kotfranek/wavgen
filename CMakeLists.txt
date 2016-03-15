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
set( CPP_LINK_FLAGS "-o3" )

# Header files locations
include_directories( 
    include 
    $ENV{TCLAP_HOME}/include
)

# Main project library
add_library( wavgen STATIC
    src/audio/SinePcm.cpp
)

# Demo application: sources
add_executable( sndtest
    src/main.cpp
)

# Demo application: required libraries
target_link_libraries( sndtest
    wavgen
)

# Set the compiler and linker flags for particular targets
set_target_properties( wavgen PROPERTIES COMPILE_FLAGS ${CPP_COMPILE_FLAGS} )
set_target_properties( sndtest PROPERTIES COMPILE_FLAGS ${CPP_COMPILE_FLAGS} )
set_target_properties( sndtest PROPERTIES LINK_FLAGS ${CPP_LINK_FLAGS} )

# Target install
install( TARGETS sndtest DESTINATION bin )
install( TARGETS wavgen DESTINATION lib )
install( DIRECTORY 
    include/ DESTINATION include/${CMAKE_PROJECT_NAME}
    FILES_MATCHING PATTERN "*.h" 
)

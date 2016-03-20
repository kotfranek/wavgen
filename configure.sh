#! /bin/sh

### Constant definitions ######################################################

# Project name
readonly PRJ_NAME="wavegen"

# External build directory
readonly BUILD_DIR="build"

# Save the current path, to be able to exit in the same directory
readonly CURRENT_DIR=$(pwd)

# Installation query phrase
readonly QUERY_INSTALL="Do you wish to install project '${PRJ_NAME}' (requires root privileges)?"

readonly USAGE_INFORMATION="Configure Script for CMake project '${PRJ_NAME}'

USAGE: 

configure.sh [OPTIONS]

OPTIONS:

-b | --build <build_type> select build configuration '${BUILD_RELEASE}' or '${BUILD_DEBUG}'
-h | --help               print this message
"

# Build configuration Release
readonly BUILD_RELEASE="Release"

# Build configuration Debug
readonly BUILD_DEBUG="Debug"

### Global Variables ##########################################################

# Make all command result
GLOB_MAKE_ALL_RESULT=-1

# CMake G command result
GLOB_CMAKE_G_RESULT=-1

# CMake build configuration default setting
GLOB_CMAKE_BUILD_CFG="${BUILD_RELEASE}"

### Functions #################################################################

# Print usage information
usage()
{
    printf "%s\n" "${USAGE_INFORMATION}"
}

# Check the Command Line Arguments
checkArgs()
{
    while [ "${1}" != "" ]; do
        case $1 in
            -b | --build )          shift
                                    GLOB_CMAKE_BUILD_CFG=${1}
                                    ;;
            -h | --help )           usage
                                    exit
                                    ;;
            * )                     usage
                                    exit 1
        esac
        shift
    done
}

# Create the CMake build environment
makeEnv()
{
    printf "%s\n" "-- Create the build directory ${BUILD_DIR}..."
    # External Build: outside of the project structure
    mkdir -p "${BUILD_DIR}"
    cd "${BUILD_DIR}"

    printf "%s\n" "-- Generate build environment from CMake input..."
    # Create the makefile based on the CMakeLists.txt up-dir
    cmake -DCMAKE_BUILD_TYPE="${GLOB_CMAKE_BUILD_CFG}" -G "Unix Makefiles" ..
    GLOB_CMAKE_G_RESULT=${?}
}

# Build project
buildProject()
{
    # Make the targets
    make all
    GLOB_MAKE_ALL_RESULT=${?}
}

# Project installation
installProject()
{
    printf "%s\n" "-- '${PRJ_NAME}' will be installed..."
    # Install project files
    make install
}

# Query for installation and proceed if agreed
installQuery()
{
    while true; do
        read -p "-- ${QUERY_INSTALL} (y/n) " yn
        case ${yn} in
            [Yy]* ) installProject; break;;
            [Nn]* ) break;;
            * ) printf "%s\n" "-- Invalid input, use Y(es) or N(o)";;
        esac
    done
}

# Called before exit
cleanUp()
{
    # Change the directory back
    cd  "${CURRENT_DIR}"
}

# Script body
main()
{
    checkArgs "${@}"
    printf "%s\n" "Configure project '${PRJ_NAME}'"
    makeEnv
    if [ ${GLOB_CMAKE_G_RESULT} -eq 0 ]; then
        buildProject
        if [ ${GLOB_MAKE_ALL_RESULT} -eq 0 ]; then
            installQuery
        else
            printf "Building '%s' failed!\n" "${PRJ_NAME}"
        fi
    else
        printf "Configuring '%s' failed!\n" "${PRJ_NAME}"
    fi
    cleanUp
}

# Call main function with all CLI arguments
main "${@}"

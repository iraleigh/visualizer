#!/usr/bin/env bash

# =============================================================================
#   build.sh
#
#   Author:     Zachary Colbert
#   Contact:    zcolbert@sfsu.edu
#
#   Purpose:
#       UNIX compilation script for the Algorithm Visualizer project.
#
#   Usage:
#       1. Ensure that you have execute permission for the script: 
#           chmod u+x build.sh
#       2. Execute the script with the command: 
#           ./build.sh
# =============================================================================


# specify the source files to be compiled
SOURCES=(
    'src/main.cpp'
    'src/data.cpp'
    'src/observer.cpp'
    'src/sort.cpp'
    'src/util.c'
    'src/visualizer.cpp'
)

# the directory containing header files to be included
INCLUDE_DIR='include'

# libraries to link against
LIBRARIES=(
    '-lSDL2'
)

# the output name of the compiled executable
EXE_NAME='visualizer'


# compile the executable using the specified parameters
g++ ${SOURCES[*]} -I ${INCLUDE_DIR} ${LIBRARIES[*]} -o ${EXE_NAME}


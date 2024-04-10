cmake_minimum_required(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})

# Set the project name to the repository name
project(${CMAKE_CURRENT_SOURCE_DIR})
# Set the C++ standard version
set(CMAKE_CXX_STANDARD 17)
# Enforce that the compiler must support this standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Set the output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# Set -g flag in order for degugger to stop at breakpoints
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_DEBUG "-g")

# Collect all .cpp files in the project
file(GLOB_RECURSE ALL_CPP_FILES_IN_REPO "*.cpp")
# Iterate over each .cpp file and create an executable for it
foreach (FILE ${ALL_CPP_FILES_IN_REPO})
    # Get the base directory name that contains the file
    get_filename_component(DIRECTORY_NAME ${FILE} DIRECTORY)
    get_filename_component(DIRECTORY_NAME ${DIRECTORY_NAME} NAME)
    # Get the base name of the .cpp file (without extension)
    get_filename_component(FILE_NAME ${FILE} NAME_WE)
    string(REGEX REPLACE "[().]" "" EXECUTABLE_NAME ${DIRECTORY_NAME}--${FILE_NAME})
    string(REGEX REPLACE "[ ']" "_" EXECUTABLE_NAME ${EXECUTABLE_NAME})
    string(REPLACE "à" "a" EXECUTABLE_NAME ${EXECUTABLE_NAME})
    string(REPLACE "â" "a" EXECUTABLE_NAME ${EXECUTABLE_NAME})
    string(REPLACE "ä" "a" EXECUTABLE_NAME ${EXECUTABLE_NAME})
    string(REPLACE "ç" "c" EXECUTABLE_NAME ${EXECUTABLE_NAME})
    string(REPLACE "é" "e" EXECUTABLE_NAME ${EXECUTABLE_NAME})
    string(REPLACE "è" "e" EXECUTABLE_NAME ${EXECUTABLE_NAME})
    string(REPLACE "ê" "e" EXECUTABLE_NAME ${EXECUTABLE_NAME})
    string(REPLACE "ë" "e" EXECUTABLE_NAME ${EXECUTABLE_NAME})
    string(REPLACE "î" "i" EXECUTABLE_NAME ${EXECUTABLE_NAME})
    string(REPLACE "ï" "i" EXECUTABLE_NAME ${EXECUTABLE_NAME})
    string(REPLACE "ô" "o" EXECUTABLE_NAME ${EXECUTABLE_NAME})
    string(REPLACE "ö" "o" EXECUTABLE_NAME ${EXECUTABLE_NAME})
    string(REPLACE "ù" "u" EXECUTABLE_NAME ${EXECUTABLE_NAME})
    string(REPLACE "û" "u" EXECUTABLE_NAME ${EXECUTABLE_NAME})
    string(REPLACE "ü" "u" EXECUTABLE_NAME ${EXECUTABLE_NAME})
    string(REGEX REPLACE "[^A-Za-z0-9_-]" "" EXECUTABLE_NAME ${EXECUTABLE_NAME})
    # Add the executable target
    add_executable(${EXECUTABLE_NAME} ${FILE})

endforeach ()

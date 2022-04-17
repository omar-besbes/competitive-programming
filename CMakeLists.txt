cmake_minimum_required(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
project("${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_CXX_STANDARD ${CMAKE_CXX_STANDARD_COMPUTED_DEFAULT})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "Executables")

file(GLOB ALL_SUBDIRECTORIES *)
foreach(DIRECTORY ${ALL_SUBDIRECTORIES})
    if(IS_DIRECTORY ${DIRECTORY} AND NOT (
    (${DIRECTORY} MATCHES ".idea") 
            OR
    (${DIRECTORY} MATCHES ".vscode")
            OR
    (${DIRECTORY} MATCHES "build")
            OR
    (${DIRECTORY} MATCHES ".get")))
        add_subdirectory(${DIRECTORY})
    endif()
endforeach()

file(GLOB ALL_CPP_FILES_IN_DIRECTORY "*.cpp")
foreach (FILE ${ALL_CPP_FILES_IN_DIRECTORY})
    get_filename_component(FILE_NAME ${FILE} NAME_WE)
    if (EXISTS ${FILE})
        get_filename_component(DIRECTORY_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
        string(REGEX REPLACE "[().]" "" TARGET_NAME ${DIRECTORY_NAME}--${FILE_NAME})
        string(REGEX REPLACE "[^A-Za-z0-9_-]" "_" TARGET_NAME ${TARGET_NAME})
        add_executable(${TARGET_NAME} ${FILE})
    endif ()
endforeach ()
cmake_minimum_required(VERSION 3.31)
project(IntroToUnrealCPP)

set(CMAKE_CXX_STANDARD 23)

# Function to create an executable for each folder
function(add_folder_executable folder_name)
    # Get all .cpp files in the folder
    file(GLOB_RECURSE SOURCE_FILES "${folder_name}/*.cpp")

    # Skip if no source files found
    if(NOT SOURCE_FILES)
        message(STATUS "No source files found in ${folder_name}, skipping...")
        return()
    endif()

    # Create executable with the folder name
    add_executable(${folder_name} ${SOURCE_FILES})

    # Set include directories to include the folder itself for header files
    target_include_directories(${folder_name} PRIVATE ${folder_name})

    message(STATUS "Added executable for ${folder_name}")
endfunction()

# Get all directories in the project root
file(GLOB FOLDERS LIST_DIRECTORIES true RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*")

# Process each directory
foreach(FOLDER ${FOLDERS})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${FOLDER} AND NOT ${FOLDER} MATCHES "^\\.")
        add_folder_executable(${FOLDER})
    endif()
endforeach()

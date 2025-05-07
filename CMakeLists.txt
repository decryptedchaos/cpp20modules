cmake_minimum_required(VERSION 3.26)
project(modc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable C++20 modules support if using GCC
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_compile_options(-fmodules-ts)
endif()

# Automatically find all .ixx module files
file(GLOB_RECURSE MODULE_FILES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/modules/*.ixx")

# Lists to collect PCM and object files
set(MODULE_TARGETS "")
set(MODULE_OBJECTS "")

# Compile each module to both .pcm and .o
foreach(MODULE_FILE ${MODULE_FILES})
  get_filename_component(MODULE_NAME ${MODULE_FILE} NAME_WE)
  set(PCM_FILE "${CMAKE_BINARY_DIR}/${MODULE_NAME}.pcm")
  set(OBJ_FILE "${CMAKE_BINARY_DIR}/${MODULE_NAME}.o")

  add_custom_command(
          OUTPUT ${PCM_FILE} ${OBJ_FILE}
          COMMAND ${CMAKE_CXX_COMPILER}
          -fmodules-ts -std=c++20
          -x c++ ${MODULE_FILE}
          -c -o ${OBJ_FILE}
          DEPENDS ${MODULE_FILE}
          COMMENT "Compiling module ${MODULE_NAME} to .pcm and .o"
  )

  list(APPEND MODULE_TARGETS ${PCM_FILE})
  list(APPEND MODULE_OBJECTS ${OBJ_FILE})
endforeach()

# Dummy target to ensure modules are built before main binary
add_custom_target(modules DEPENDS ${MODULE_TARGETS} ${MODULE_OBJECTS})

# Build main executable and link object files
add_executable(modc modc.cpp ${MODULE_OBJECTS})
add_dependencies(modc modules)
target_compile_options(modc PRIVATE -fmodules-ts)

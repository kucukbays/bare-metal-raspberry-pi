
# Usage: "cmake -DCMAKE_TOOLCHAIN_FILE=toolchain-arm-none-eabi.cmake ..."  --> To configure and generate UNIX Makefile. 

# CMAKE_SYSTEM_NAME CMake variable is mandatory and indicates the name of the target system.
# If the CMAKE_SYSTEM_NAME CMake variable is preset, the CMAKE_CROSSCOMPILING CMake variable is automatically set to TRUE.
# If the target system is an embedded system without OS, set CMAKE_SYSTEM_NAME to "Generic".
SET(CMAKE_SYSTEM_NAME Generic)

# Not a CMake variable. The toolchain prefix for all toolchain executables.
SET(TOOLCHAIN_PREFIX arm-none-eabi)

# CMake cannot guess the target system and which compiler it should use, so CMAKE_C_COMPILER/CMAKE_CXX_COMPILER CMake variables have to be preset.
# If the toolchain is a GNU toolchain, you only need to set one of both: CMAKE_C_COMPILER/CMAKE_CXX_COMPILER.
SET(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}-g++)
SET(CMAKE_ASM_COMPILER ${TOOLCHAIN_PREFIX}-g++)

# Set and cache the objcopy tool of the cross-compiler toolchain.
SET(CMAKE_OBJCOPY ${TOOLCHAIN_PREFIX}-objcopy)
SET(CMAKE_OBJCOPY "${CMAKE_OBJCOPY}" CACHE FILENAME "" FORCE)

# CMAKE_CXX_FLAGS is a command-line string fragment. Therefore, multiple options should be separated by spaces, and options with spaces should be quoted.
# Compiler flags regarding the processor.
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=armv8-a+crc")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mcpu=cortex-a53")

# Compiler flags regarding the floating point unit.
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mfpu=vfp")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mfloat-abi=hard")

# The CACHE is available to all of the CMake files in the build system. 
# If we set a variable in this toolchain file it only has local scope (meaning only this file can see the value we set to this variable). 
# Therefore we force CMake to add this to the cache.
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" CACHE STRING "")
SET(CMAKE_ASM_FLAGS "${CMAKE_CXX_FLAGS}" CACHE STRING "")

# When compiling a test project, CMake does not pass variables to it by default, e.g. the necessary '-nostartfiles' compiler flag found in the
# CMakeLists.txt file is not passed to the compiler. Thus, to skip compiler tests: CMAKE_CXX_COMPILER_WORKS is set to 1 and cached.
SET(CMAKE_CXX_COMPILER_WORKS 1 CACHE INTERNAL "")





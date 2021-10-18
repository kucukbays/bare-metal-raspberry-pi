
# Assembly files (.s) in the source list are ignored completely by CMake 
# unless we tell CMake in the project definition that we're using assembly files.
# "If enabling ASM, list it last so that CMake can check whether compilers for other languages like C/C++ work for assembly too."
PROJECT(BareMetal-RPi CXX ASM)

# Append project-specific compiler flags.
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -nostartfiles")

SET(TARGET_NAME kernel7.elf)

# Add an executable to the project using the specified source files.
ADD_EXECUTABLE( 
    ${TARGET_NAME}		
    src/start.s
    src/main.cpp
)

# Add a custom command to the post-build step of the target to convert the .elf target output to a binary .img file.
ADD_CUSTOM_COMMAND(
    TARGET ${TARGET_NAME} 
    POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} ./${TARGET_NAME} -O binary ./kernel7.img
    COMMENT "Converting the .elf output file to a binary .img file..." 
)
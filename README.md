# bare-metal-raspberry-pi

### Credits

This work is based on [Brian Sidebotham's tutorial](https://www.valvers.com/open-software/raspberry-pi/bare-metal-programming-in-c-part-1/) on bare metal programming in C.

### Build & Run

CMake is required for platform-independent compilation of bare-metal-raspberry-pi. If you do not have CMake installed on your computer, please click [here](https://cmake.org/download/) to go to the official website of CMake and install CMake version 3.13 or higher.

##### On Linux/MacOS:

- Clone the repository:
```
git clone <repo-path>
```
- Go to the repo root folder and make a directory for the CMake to produce build outputs to a separate directory:
```
cd <repo-root-folder>
mkdir build
```
- Run the CMake command below to generate the Makefile inside the build/ directory:
```
cmake -DCMAKE_TOOLCHAIN_FILE=toolchain-arm-none-eabi.cmake -Bbuild/ -S./ 
```
- Go to the build/ directory and run the 'make' command to generate the 'kernel7.img' binary:
```
cd build
make
```
- At this point, 'kernel7.img' binary must have been built successfully.


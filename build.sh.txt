#!/bin/bash

# Create a build directory if it doesn't exist
if [ ! -d "build" ]; then
  mkdir build
fi

# Navigate to the build directory
cd build

# Run CMake to configure the project
cmake ..

# Build the project
make

# Navigate back to the root directory
cd ..
#!/bin/bash

PROJECT_DIR=$(pwd)

mkdir -p build

cd build

cmake ..

cmake --build . -j$(nproc)

./badlang

cd "$PROJECT_DIR"

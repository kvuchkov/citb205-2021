cmake_minimum_required(VERSION 3.5)
project(add_executable(lab09 ${SOURCE_FILES})
)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/product.cpp src/item.cpp src/invoice.cpp src/textprinter.cpp src/discount.cpp)
add_executable(lab09 ${SOURCE_FILES})

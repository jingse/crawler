# cmake_minimum_required(VERSION <specify CMake version here>)
project(Lab C)

set(CMAKE_C_STANDARD 99)

add_executable(Lab Main.c Header.h Pagerank.c BloomFilter.c WebCrawler.c)
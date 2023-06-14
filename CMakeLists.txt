cmake_minimum_required(VERSION 3.25)
project(account_book)

set(CMAKE_CXX_STANDARD 11)

add_executable(account_book main.cpp account_item.h operations.cpp common.h menus.cpp read_input.cpp)

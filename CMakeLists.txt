cmake_minimum_required(VERSION 3.22)
project(termux-usb-emu)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(termux_usb
		main.cpp
		str_trim.cpp
		str_trim.hpp)

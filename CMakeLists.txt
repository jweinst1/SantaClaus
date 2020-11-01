cmake_minimum_required(VERSION 3.5)

project(santa_claus VERSION 0.0.1)

# Option to install targets to env location
if(DEFINED ENV{SANTA_CLAUS_HOME})
     message("-- Will install TEMPLATE binaries and libraries to location: " $ENV{SANTA_CLAUS_HOME})
	 set(CMAKE_INSTALL_PREFIX $ENV{SANTA_CLAUS_HOME})
else(DEFINED ENV{SANTA_CLAUS_HOME})
     message("-- Will install TEMPLATE binaries and libraries to location: " ${CMAKE_CURRENT_BINARY_DIR})
	 set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR})
endif(DEFINED ENV{SANTA_CLAUS_HOME})

# Build type
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

# Options
option(WITH_testing "Allows tests to be run" ON)

if(WITH_testing MATCHES ON)
   enable_testing()
endif(WITH_testing MATCHES ON)
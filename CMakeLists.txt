cmake_minimum_required(VERSION 3.5)

project(santa_claus VERSION 0.0.1)

# Option to install targets to env location
if(DEFINED ENV{SANTA_CLAUS_HOME})
     message("-- Will install SantaClaus binaries and libraries to location: " $ENV{SANTA_CLAUS_HOME})
     set(CMAKE_INSTALL_PREFIX $ENV{SANTA_CLAUS_HOME})
else(DEFINED ENV{SANTA_CLAUS_HOME})
     message("-- Will install SantaClaus binaries and libraries to the default  location: " ${CMAKE_INSTALL_PREFIX})
endif(DEFINED ENV{SANTA_CLAUS_HOME})

# Build type
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

# Check if some headers are present
include(CheckIncludeFile)
if(UNIX)
    CHECK_INCLUDE_FILE("errno.h" HAVE_ERRNO_HEADER)
    if(HAVE_ERRNO_HEADER)
        add_definitions(-DHAVE_ERRNO)
    endif(HAVE_ERRNO_HEADER)
endif(UNIX)

CHECK_INCLUDE_FILE("stdint.h" HAVE_STDINT_HEADER)
if(HAVE_STDINT_HEADER)
    add_definitions(-DHAVE_STDINT)
endif(HAVE_STDINT_HEADER)

# Options
option(WITH_testing "Allows tests to be run" ON)

if(WITH_testing MATCHES ON)
   enable_testing()
endif(WITH_testing MATCHES ON)

set(SANTA_CLAUS_SOURCES 
    toys-sc.c
)

add_library(santa_claus_l STATIC "${SANTA_CLAUS_SOURCES}")

add_executable(santa_claus main.c)
target_link_libraries(santa_claus santa_claus_l)

install(TARGETS santa_claus DESTINATION bin)



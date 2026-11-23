cmake_minimum_required(VERSION 3.16)
project(live-voice-changer CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(livevoicechanger
    src/main.cpp
    src/engine.cpp
    src/io.cpp
    src/presets.cpp
)

target_include_directories(livevoicechanger PRIVATE include)

if(WIN32)
    target_link_libraries(livevoicechanger PRIVATE userenv)
endif()

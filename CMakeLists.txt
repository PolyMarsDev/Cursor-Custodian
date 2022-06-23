cmake_minimum_required(VERSION 3.19)

project(cursor-custodian VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

# Find SDL2, SDL2_image and SDL2_ttf libraries
if( ${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
    set(USE_FLAGS "-s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS=['png'] -s USE_SDL_TTF=2 -s USE_SDL_MIXER=2 -s USE_FREETYPE=1 --preload-file res")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${USE_FLAGS}")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${USE_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${USE_FLAGS}")
    set(CMAKE_EXECUTABLE_SUFFIX .html)
else()
    find_package(SDL2 REQUIRED)
    find_package(SDL2_image REQUIRED)
    find_package(SDL2_ttf REQUIRED)
    find_package(SDL2_mixer REQUIRED)
    set(SDL2_LIBRARIES SDL2::Main SDL2::Image SDL2::TTF SDL2::Mixer)
endif()

# Build game
add_compile_options(-Wall -Wextra)
include_directories(include)

FILE(GLOB_RECURSE SOURCES src/**.cpp)
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

file(COPY res DESTINATION ${CMAKE_BINARY_DIR})

# Link SDL2::Main, SDL2::Image and SDL2::TTF to our project
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
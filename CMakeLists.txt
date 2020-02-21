
cmake_minimum_required(VERSION 3.10)

project(Alpha)

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE INC_FILES ${PROJECT_SOURCE_DIR}/*.h)

find_package(SDL2 REQUIRED)

add_executable(alpha ${SRC_FILES} ${INC_FILES})

target_include_directories(alpha PUBLIC include)


message("sdl2 include dir:")
message( ${SDL2_INCLUDE_DIRS})
target_include_directories(alpha PUBLIC ${SDL2_INCLUDE_DIRS})


message("sdl2 link libraries:")
message( ${SDL2_LIBRARIES})
target_link_libraries(alpha ${SDL2_LIBRARIES})

cmake_minimum_required(VERSION 3.13)
project(Snake)

if(WIN32 AND MINGW)
  set(SFML_DIR "../SFML-2.6.1/build")
endif()

find_package(SFML COMPONENTS network audio graphics window system REQUIRED)
add_executable(Snake main.cpp mainScene.cpp snake.cpp food.cpp deathScene.cpp)

if(WIN32 AND MINGW)
  target_link_libraries(Snake PRIVATE sfml-graphics sfml-window sfml-system)
  target_include_directories(Snake PRIVATE ../SFML-2.6.1/include)
  # target_link_options(Snake PRIVATE "-mwindows")
endif()

file(COPY "${CMAKE_SOURCE_DIR}/font" DESTINATION "${CMAKE_BINARY_DIR}")
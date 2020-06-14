cmake_minimum_required(VERSION 3.5)

project(Tricky-n-Class-Classifier LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(xtensor REQUIRED)
find_package(Qt5 COMPONENTS Widgets Core Charts Gui REQUIRED)

add_executable(Tricky-n-Class-Classifier
  main.cpp
  chartview.cpp
  chartview.h
)

target_include_directories(Tricky-n-Class-Classifier PUBLIC ${xtensor_INCLUDE_DIRS})
target_link_libraries(Tricky-n-Class-Classifier PUBLIC xtensor PRIVATE Qt5::Core Qt5::Widgets Qt5::Charts Qt5::Gui)
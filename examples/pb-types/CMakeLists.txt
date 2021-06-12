cmake_minimum_required(VERSION 3.16)
project(pb-types LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

INCLUDE_DIRECTORIES(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/../qtpropertybrowser/
  ${CMAKE_CURRENT_BINARY_DIR}
  )
find_package(Qt6 COMPONENTS Widgets)
file(GLOB_RECURSE pbs "../qtpropertybrowser/*.cpp")

add_executable(${PROJECT_NAME}
    main.cpp
    ${pbs}
    ${UI_SOURCES} ${UI_HEADERS} ${UI_FILES} ${DB_SOURCES} ${DB_HEADERS} ${UTILS_SOURCES}
    ${UTILS_HEADERS} demo.qrc)
target_link_libraries(${PROJECT_NAME} Qt::Widgets)


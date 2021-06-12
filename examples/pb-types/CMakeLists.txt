set(target_name pb-types)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

INCLUDE_DIRECTORIES(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/qtpropertybrowser
  ${CMAKE_CURRENT_BINARY_DIR}
  )
find_package(Qt6 COMPONENTS Widgets)
file(GLOB_RECURSE pbs "${CMAKE_SOURCE_DIR}/qtpropertybrowser/*.cpp")

add_executable(${target_name}
    main.cpp
    ${pbs}
    ${UI_SOURCES} ${UI_HEADERS} ${UI_FILES} ${DB_SOURCES} ${DB_HEADERS} ${UTILS_SOURCES}
    ${UTILS_HEADERS} demo.qrc)
target_link_libraries(${target_name} Qt::Widgets)


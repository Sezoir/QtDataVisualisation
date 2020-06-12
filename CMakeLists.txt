cmake_minimum_required(VERSION 3.13)

project(DataVisualisation LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QT_VERSION_REQ "5.15")

list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMake/)

# Get qt packages
find_package(Qt5 COMPONENTS Core Quick REQUIRED)

# Get dependencies packages
set(QXLSX_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/QXlsx)
find_package(QXlsx CONFIG REQUIRED)

# Store default source files for root files
set(SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Bootloader/Startup.cpp
    qml.qrc)

# Store default header files for root files
set(HEADER_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/Bootloader/Startup.hpp)

## Get all files from app
file(GLOB_RECURSE APP_SOURCE_FILES App/*.cpp)
file(GLOB_RECURSE APP_HEADER_FILES App/*.hpp)

# Append results to source/header file variables
list(APPEND SOURCE_FILES ${APP_SOURCE_FILES})
list(APPEND HEADER_FILES ${APP_HEADER_FILES})

message(${HEADER_FILES})

# Add executable using glob files
add_executable(DataVisualisation
  ${SOURCE_FILES}
  ${HEADER_FILES}
)

# Add include directories found from glob
target_include_directories(DataVisualisation PRIVATE ${HEADER_FILES})


target_compile_definitions(DataVisualisation
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

# Link libraries
target_link_libraries(DataVisualisation PRIVATE
    Qt5::Core
    Qt5::Quick
    QXlsx)

# Copy excel dataset to build
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Dataset/global-city-population-estimates.xlsx
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

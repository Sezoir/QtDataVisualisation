cmake_minimum_required(VERSION 3.5)

project(DataVisualisation LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QT_VERSION_REQ "5.15")

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

add_executable(DataVisualisation
  main.cpp
  Bootloader/Startup.cpp
  Bootloader/Startup.hpp
  qml.qrc
)

target_compile_definitions(DataVisualisation
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)


target_link_libraries(DataVisualisation PRIVATE
    Qt5::Core
    Qt5::Quick)

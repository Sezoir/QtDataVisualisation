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
  qml.qrc
)

target_compile_definitions(DataVisualisation
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)


target_link_libraries(DataVisualisation PRIVATE
    Qt5::Core
    Qt5::Quick)




#set(CMAKE_AUTOMOC ON)
#QT5_WRAP_UI( UI_HDRS ${UI_FILES} )

#ADD_EXECUTABLE(${MOC_HEADERS})

#target_link_libraries(${PROJECT_NAME}
#  Qt5::Core
#  Qt5::Quick
#  Qt5::Widgets
#  Qt5::Gui
#)

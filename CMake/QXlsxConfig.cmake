### Note that we expect the path to the qxlsx lib to be given
cmake_minimum_required(VERSION 3.16)

#add_definitions(
#    -DQT_NO_KEYWORDS
#    -DQT_NO_CAST_TO_ASCII
#    -DQT_NO_CAST_FROM_ASCII
#    -DQT_STRICT_ITERATORS
#    -DQT_NO_URL_CAST_FROM_STRING
#    -DQT_NO_CAST_FROM_BYTEARRAY
#    -DQT_USE_QSTRINGBUILDER
#    -DQT_NO_SIGNALS_SLOTS_KEYWORDS
#    -DQT_USE_FAST_OPERATOR_PLUS
#    -DQT_DISABLE_DEPRECATED_BEFORE=0x050c00
#)

set(QXLSX_DEFINITIONS
    -DQT_NO_KEYWORDS
    -DQT_NO_CAST_TO_ASCII
    -DQT_NO_CAST_FROM_ASCII
    -DQT_STRICT_ITERATORS
    -DQT_NO_URL_CAST_FROM_STRING
    -DQT_NO_CAST_FROM_BYTEARRAY
    -DQT_USE_QSTRINGBUILDER
    -DQT_NO_SIGNALS_SLOTS_KEYWORDS
    -DQT_USE_FAST_OPERATOR_PLUS
    -DQT_DISABLE_DEPRECATED_BEFORE=0x050c00)

add_library(QXlsx)

target_compile_definitions(QXlsx PRIVATE ${QXLSX_DEFINITIONS})

# Define target sources
file(GLOB_RECURSE files ${QXLSX_DIR}/QXlsx/source/*.cpp ${QXLSX_DIR}/QXlsx/header/*.h)

target_sources(QXlsx PRIVATE
  ${files}
)

target_link_libraries(QXlsx PRIVATE Qt5::Core Qt5::Gui Qt5::GuiPrivate)
target_include_directories(QXlsx PUBLIC ${QXLSX_DIR}/QXlsx/header)

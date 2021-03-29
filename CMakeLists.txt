cmake_minimum_required(VERSION 3.18)

project(sample-conan-and-qt VERSION 1.0)

enable_language(CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 5.15.0 EXACT REQUIRED COMPONENTS Qml Quick LinguistTools)

set(SOURCE_FILES
    main.cpp)

set(RESOURCE_FILES
    demo.qrc)

set(QML_FILES
    Basic.qml
    basic-b2qt.qml
    content/AutoScroller.qml
    content/HandwritingModeButton.qml
    content/TextArea.qml
    content/TextField.qml)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} Basic_en.ts Basic_ru.ts)

add_executable(virtualkeyboard
    ${SOURCE_FILES}
    ${RESOURCE_FILES}
    ${QML_FILES}
    ${QM_FILES})

target_compile_definitions(virtualkeyboard
    PRIVATE MAIN_QML=\"basic-b2qt.qml\")
    # PRIVATE MAIN_QML=\"Basic.qml\")

target_link_libraries(virtualkeyboard
    PRIVATE Qt5::Qml Qt5::Quick)

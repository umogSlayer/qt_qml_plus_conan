cmake_minimum_required(VERSION 3.18)

project(ui-app)

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

set(TS_FILES
    Basic_en.ts
    Basic_ru.ts)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
message("QM_FILES: ${QM_FILES}")

add_executable(${PROJECT_NAME}
    ${SOURCE_FILES}
    ${RESOURCE_FILES}
    ${QML_FILES}
    ${TS_FILES}
    ${QM_FILES})

target_compile_definitions(${PROJECT_NAME}
    PRIVATE MAIN_QML=\"basic-b2qt.qml\")

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        OnyxCorp::rand-lib)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt5::Qml
        Qt5::Quick)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        AUTOMOC ON
        AUTORCC ON)

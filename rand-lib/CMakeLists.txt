cmake_minimum_required(VERSION 3.18)

project(rand-lib)

set(SOURCE_FILES
    rand-lib.cpp)

set(HEADER_FILES
    rand-lib.h)

add_library(${PROJECT_NAME} STATIC
    ${SOURCE_FILES}
    ${HEADER_FILES})

# Apply namespace to a library created here
add_library(OnyxCorp::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

if(CONAN_USE_CMAKE_GENERATOR)
    target_link_libraries(${PROJECT_NAME}
        PRIVATE
            CONAN_PKG::openssl)
else()
    target_link_libraries(${PROJECT_NAME}
        PRIVATE
            OpenSSL::SSL
            OpenSSL::Crypto)
endif()

target_include_directories(${PROJECT_NAME}
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

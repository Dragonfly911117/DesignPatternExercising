cmake_minimum_required(VERSION 4.0)
project(DependencyInversionPrinciple)

set(CMAKE_CXX_STANDARD 20)

CPMAddPackage("gh:google/googletest@1.17.0")


add_executable(${PROJECT_NAME})

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_sources(
        ${PROJECT_NAME}
        PRIVATE
        ${SRC_DIR}/EmailSender.cpp
        ${SRC_DIR}/NotificationSender.cpp
        ${SRC_DIR}/MessengerFactory.cpp
        ${SRC_DIR}/SMSSender.cpp
        
        main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_include_directories(${PROJECT_NAME} PRIVATE ${gtest_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} gtest gtest_main)
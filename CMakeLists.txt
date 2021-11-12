cmake_minimum_required(VERSION 3.15)
project(bspline)


add_library(bspline 
    BSpline/BSplineLib.cpp
)
target_include_directories(bspline PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)
if(BUILD_SHARED_LIBS)
    target_compile_definitions(bspline 
        PUBLIC BSPLINE_SHARED
        PRIVATE BSPLINE_BUILD
    )
endif()

add_executable(bspline_test
    Tests/C++/bspline.cpp
    Tests/C++/options.cpp
)
target_include_directories(bspline PRIVATE
    Tests/C++
)
target_link_libraries(bspline_test bspline)

install(
    DIRECTORY BSpline
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*"
)

install(TARGETS bspline_test
    RUNTIME DESTINATION bin
)
install(TARGETS bspline
    EXPORT ${PROJECT_NAME}-export
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
install(EXPORT ${PROJECT_NAME}-export
FILE
${PROJECT_NAME}Targets.cmake
NAMESPACE
    ${PROJECT_NAME}::
DESTINATION
    cmake
)
configure_file(bspline-config.cmake.in ${PROJECT_NAME}-config.cmake @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME}-config.cmake DESTINATION cmake/)
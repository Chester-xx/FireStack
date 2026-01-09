project(BlendViewer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Quick)

add_executable(BlendViewer
    main.cpp
)

target_link_libraries(BlendViewer PRIVATE Qt6::Quick)

if (WIN32)
    add_custom_command(TARGET BlendViewer POST_BUILD
        COMMAND "${Qt6_DIR}/../../../bin/windeployqt.exe"
                "$<TARGET_FILE:BlendViewer>"
        COMMENT "Deploying Qt runtime with windeployqt"
    )
endif()
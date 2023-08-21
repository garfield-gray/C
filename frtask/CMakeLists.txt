cmake_minimum_required(VERSION 3.16)

project(frtask VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appfrtask
    main.cpp
    LocationManager.cpp
    LocationManager.h
    qml.qrc

)

qt_add_qml_module(appfrtask
    URI frtask
    VERSION 1.0
    QML_FILES Main.qml LocationManager.qml
)



qt_add_resources(appfrtask qml
    FILES
        Back.jpg
        Eiffel.jpg
        image.jpg
        rihanna.jpg
        Rihanna.jpg
        Ariana.jpg
        white.png
        edit.png
        delete.png
)




set_target_properties(appfrtask PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appfrtask
    PRIVATE Qt6::Quick
)

install(TARGETS appfrtask
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

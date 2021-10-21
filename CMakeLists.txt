cmake_minimum_required(VERSION 3.20)
project(TasQ_Application)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories(TasQ_Application ${CMAKE_SOURCE_DIR}/lib/include)

find_package(Qt6 COMPONENTS
        Core
        Gui
        widgets
        Network
        REQUIRED)

find_library(CURL libcurl lib/lib)

add_executable(TasQ_Application
        src/main.cpp
        src/widgets/MainWindow/MainWindow.cpp
        include/widgets/MainWindow.h
        src/widgets/MainWindow/MainWindow.ui
        src/models/User.cpp include/models/User.h
        include/models/Models.h
        src/models/School.cpp include/models/School.h
        src/models/Course.cpp include/models/Course.h
        src/models/Enums.cpp include/models/Enums.h
        src/models/Event.cpp include/models/Event.h
        src/models/Reminder.cpp include/models/Reminder.h
        src/models/Todo.cpp include/models/Todo.h
        src/models/Application.cpp include/models/Application.h
        include/net/net.h src/net/net.cpp include/models/Models.h)

target_link_libraries(TasQ_Application
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Network
        ${CURL}
        )

if (WIN32)
    set(DEBUG_SUFFIX)
    if (CMAKE_BUILD_TYPE MATCHES "Debug")
#        set(DEBUG_SUFFIX "d") TODO: Uncomment to enable gui debugging if needed
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()

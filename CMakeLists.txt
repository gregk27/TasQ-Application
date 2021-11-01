cmake_minimum_required(VERSION 3.20)
project(TasQ_Application)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories("${PROJECT_SOURCE_DIR}/include")

find_package(Qt6 COMPONENTS
        Core
        Gui
        widgets
        REQUIRED)

add_executable(TasQ_Application
        src/main.cpp
        src/widgets/MainWindow/MainWindow.cpp
        include/widgets/MainWindow.h
        src/widgets/MainWindow/MainWindow.ui
        include/widgets/tabnavigator.h
        src/widgets/TabNavigator/tabnavigator.cpp
        src/widgets/TabNavigator/tabnavigator.ui
        include/widgets/schedulescreen.h
        src/widgets/ScheduleScreen/schedulescreen.cpp
        src/widgets/ScheduleScreen/schedulescreen.ui
        include/widgets/profilescreen.h
        src/widgets/ProfileScreen/profilescreen.cpp
        src/widgets/ProfileScreen/profilescreen.ui
        include/widgets/assignmentsscreen.h
        src/widgets/AssignmentsScreen/assignmentsscreen.cpp
        src/widgets/AssignmentsScreen/assignmentsscreen.ui
        include/widgets/todoscreen.h
        src/widgets/ToDoScreen/todoscreen.cpp
        src/widgets/ToDoScreen/todoscreen.ui
        include/widgets/schedulefilter.h
        src/widgets/ScheduleFilter/schedulefilter.cpp
        src/widgets/ScheduleFilter/schedulefilter.ui
        include/widgets/scheduleweekview.h
        src/widgets/ScheduleWeekView/scheduleweekview.cpp
        src/widgets/ScheduleWeekView/scheduleweekview.ui
        include/widgets/schedulelistview.h
        src/widgets/ScheduleListView/schedulelistview.cpp
        src/widgets/ScheduleListView/schedulelistview.ui
        src/models/User.cpp include/models/User.h
        src/models/ModelBase.cpp include/models/ModelBase.h
        src/models/School.cpp include/models/School.h
        src/models/Course.cpp include/models/Course.h
        src/models/Enums.cpp include/models/Enums.h
        src/models/Event.cpp include/models/Event.h
        src/models/Reminder.cpp include/models/Reminder.h
        src/models/Todo.cpp include/models/Todo.h
        src/models/Application.cpp include/models/Application.h
        )

target_link_libraries(TasQ_Application
        Qt::Core
        Qt::Gui
        Qt::Widgets
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

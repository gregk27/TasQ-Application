cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
project(TasQ-Application VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/lib/include")

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/lib/bin/cacert.pem
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/lib/bin)


find_package(Qt6 COMPONENTS
        Core
        Gui
        widgets
        Network
        REQUIRED)

find_library(CURL libcurl lib/lib)

set(PROJECT_WIDGETS
        src/main.cpp
        src/widgets/MainWindow/MainWindow.cpp
        include/widgets/MainWindow.h
        src/widgets/MainWindow/MainWindow.ui
        src/widgets/ProfileScreen/profilescreen.cpp
        include/widgets/profilescreen.h
        src/widgets/ProfileScreen/profilescreen.ui
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
        include/widgets/monthcalendar.h
        src/widgets/monthcalendar/monthcalendar.cpp 
        src/widgets/monthcalendar/monthcalendar.ui 
        include/widgets/monthview.h
        include/widgets/monthview.h
        src/widgets/monthview/monthview.cpp
        src/widgets/monthview/monthview.ui
        include/widgets/termview.h
        src/widgets/termview/termview.cpp
        src/widgets/termview/termview.ui
        src/widgets/login_page/login.cpp
        src/widgets/login_page/login.ui
        include/widgets/login.h
        src/widgets/login_page/registerdialog.cpp
        src/widgets/login_page/registerdialog.ui
        include/widgets/registerdialog.h
        src/widgets/AddRemoveClass/addremoveclass.cpp include/widgets/addremoveclass.h src/widgets/AddRemoveClass/addremoveclass.ui)

set(PROJECT_BACKEND
        src/models/User.cpp include/models/User.h
        include/models/Models.h
        src/models/School.cpp include/models/School.h
        src/models/Course.cpp include/models/Course.h
        src/models/Enums.cpp include/models/Enums.h
        src/models/Event.cpp include/models/Event.h
        src/models/Reminder.cpp include/models/Reminder.h
        src/models/Todo.cpp include/models/Todo.h
        include/net/net.h src/net/net.cpp
        src/net/auth.cpp include/net/auth.h src/net/schools.cpp include/net/schools.h src/net/endpoints.cpp src/net/subscriptions.cpp include/models/NetModel.h src/models/NetModel.cpp include/net/endpoints.h include/net/subscriptions.h include/net/api.h src/net/api.cpp
        include/utils.h src/utils.cpp)

add_executable(TasQ-Application
        src/main.cpp
        ${PROJECT_WIDGETS}
        ${PROJECT_BACKEND}
        src/ApplicationController.cpp include/ApplicationController.h)


target_link_libraries(TasQ-Application
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Network
        ${CURL}
)

set_target_properties(TasQ-Application PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

#add_executable(TasQ_NoQt
#        src/models/User.cpp include/models/User.h
#        src/models/School.cpp include/models/School.h
#        src/models/Course.cpp include/models/Course.h
#        src/models/Enums.cpp include/models/Enums.h
#        src/models/Event.cpp include/models/Event.h
#        src/models/Reminder.cpp include/models/Reminder.h
#        src/models/Todo.cpp include/models/Todo.h
#        src/models/Application.cpp include/models/Application.h
#        src/net/auth.cpp include/net/auth.h
#        test/models/TestUser.cpp
#        test/models/TestCourse.cpp
#        test/models/TestEvent.cpp
#        test/models/TestEnums.cpp
#        test/models/TestTodo.cpp
#        test/models/TestReminder.cpp
#        test/models/TestSchool.cpp src/net/schools.cpp include/net/schools.h src/net/endpoints.cpp src/net/subscriptions.cpp include/models/NetModel.h src/models/NetModel.cpp include/net/api.h src/net/api.cpp)

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

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(TasQ-Application)
endif()

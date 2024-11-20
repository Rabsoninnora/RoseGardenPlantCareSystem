cmake_minimum_required(VERSION 3.5)

project(RoseGardenPlantCareSystem VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets  Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS  Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS  Sql)

set(PROJECT_SOURCES
        main.cpp
        mainwindowplantcare.cpp

        mainwindowplantcare.h
        mainwindowplantcare.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(RoseGardenPlantCareSystem
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        secdialog.h secdialog.cpp secdialog.ui
        resource.qrc
        addplant.h addplant.cpp addplant.ui
        viewplants.h viewplants.cpp viewplants.ui
        addgardener.h addgardener.cpp addgardener.ui
        species.h species.cpp species.ui
        gardenerdetails.h gardenerdetails.cpp gardenerdetails.ui
        adminpanel.h adminpanel.cpp adminpanel.ui
        databaseheader.h
        addgardentool.h addgardentool.cpp addgardentool.ui
        viewgardentools.h viewgardentools.cpp viewgardentools.ui
        addsystemadmin.h addsystemadmin.cpp addsystemadmin.ui
        viewsystemadmin.h viewsystemadmin.cpp viewsystemadmin.ui
        availableplants.h availableplants.cpp availableplants.ui
        suppliers.h suppliers.cpp suppliers.ui

        plantdetail.h plantdetail.cpp plantdetail.ui
        mydb.h mydb.cpp
        adminlogin.h adminlogin.cpp adminlogin.ui
        userlogin.h userlogin.cpp userlogin.ui

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET RoseGardenPlantCareSystem APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(RoseGardenPlantCareSystem SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(RoseGardenPlantCareSystem
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(RoseGardenPlantCareSystem PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql )

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.RoseGardenPlantCareSystem)
endif()
set_target_properties(RoseGardenPlantCareSystem PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS RoseGardenPlantCareSystem
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(RoseGardenPlantCareSystem)
endif()

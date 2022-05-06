cmake_minimum_required(VERSION 2.8)
project(MissionStatus)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_ROOT /home/recursion/Qt/5.15.2/gcc_64)
set(QT_PLUGIN_PATH ${QT_ROOT}/plugins)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH ${QT_ROOT}/lib/cmake)
set(QT_QMAKE_EXECUTABLE ${QT_ROOT}/bin/qmake)

set(QT_MOC_EXECUTABLE ${QT_ROOT}/bin/moc)
set(QT_RCC_EXECUTABLE ${QT_ROOT}/bin/rrc)
set(QT_UIC_EXECUTABLE ${QT_ROOT}/bin/uic)


find_package(Qt5 COMPONENTS Core Widgets DataVisualization REQUIRED)
find_package(Boost 1.71 COMPONENTS filesystem REQUIRED)

set(CXX_SRCS
  main.cpp
  
  mission_status_window.cpp
  summary_view.cpp
  drives_view.cpp
  machines_view.cpp
  
  drive_widget.cpp
  machine_widget.cpp
  
  dataQuery/dataquery.cpp
  dataQuery/cpudataquery.cpp
  dataQuery/ramdataquery.cpp
  dataQuery/queryresource.cpp
  
  widgets/cpuwidget.cpp
  widgets/ramwidget.cpp
  widgets/performancewidget.cpp
  
  painters/performancepainter.cpp
  painters/painterutils.cpp
  painters/graphpainter.cpp
  painters/graphmulticolorpainter.cpp
  painters/barspainter.cpp
  
)

include_directories(
	/home/recursion/Qt/5.15.2/gcc_64/include/QtWidgets
	/home/recursion/Qt/5.15.2/gcc_64/include/QtCore
	/usr/include/boost/
)

add_executable(${PROJECT_NAME} ${CXX_SRCS})

target_link_libraries(${PROJECT_NAME}
  Qt5::Core
  Qt5::Widgets
)

install(TARGETS ${PROJECT_NAME} CONFIGURATIONS Debug RUNTIME DESTINATION bin)

cmake_minimum_required(VERSION 3.6)
project(switch_project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# add library tins located in dir
include_directories(/usr/local/include/include /usr/include/qt4)
link_directories(/usr/local/lib /usr/lib/x86_64-linux-gnu)

# qt config
set(SOURCE_FILES Controller.cpp Port_sniffer.cpp Port_sniffer.h MAC_table.cpp MAC_table.h Switch_gui.cpp Switch_gui.h ui_switch_GUI.h Filters.cpp Filters.h)

find_package(Qt4 REQUIRED QtCore QtGui)
include(${QT_USE_FILE})
set(CMAKE_AUTOMOC ON)
QT4_WRAP_UI(UI_HEADERS switch_GUI.ui)
QT4_WRAP_CPP(MOC_SRCS ui_switch_GUI_old.h)

#add_executable(test_Port_sniffer ${SOURCE_FILES} ${UI_HEADERS} ${MOC_SRCS})
#target_link_libraries(test_Port_sniffer libtins.so Qt4::QtCore Qt4::QtGui) #pthread
# qt config end


#add_executable(interfaces iflist.cpp)
#target_link_libraries(interfaces libtins.so)

add_executable(switch ${SOURCE_FILES} ${UI_HEADERS} ${MOC_SRCS})
target_link_libraries(switch libtins.so Qt4::QtCore Qt4::QtGui)

#add_executable(controller Controller.cpp ${UI_HEADERS} ${MOC_SRCS})
#target_link_libraries(controller Qt4::QtCore Qt4::QtGui)
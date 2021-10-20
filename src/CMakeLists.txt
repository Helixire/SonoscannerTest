cmake_minimum_required(VERSION 3.13)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(sono "")

target_sources(sono
	PRIVATE
		main.cpp
		Parser.cpp
		MainWindow/MainWindow.cpp
		MainWindow/MainWindow.ui
		Parser.h
		MainWindow/MainWindow.h
)

target_link_libraries(sono PRIVATE Qt5::Widgets)

add_library(sono_lib $<TARGET_OBJECTS:sono>)
target_include_directories(sono_lib PUBLIC .)
target_link_libraries(sono_lib PUBLIC Qt5::Widgets)

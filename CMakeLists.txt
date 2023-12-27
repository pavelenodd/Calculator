cmake_minimum_required(VERSION 3.24)

project(Calculator_Wody)

#аока что Qt отключён
# Найти пакет Qt6
#find_package(Qt6 COMPONENTS Widgets REQUIRED)

# Включить автоматическую обработку moc, rcc и uic
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)

# каталоги для поиска заголовочных файлов
include_directories(${CMAKE_SOURCE_DIR}/include)

#  исполняемые файлы
add_executable(${PROJECT_NAME}
    src/main.cpp

    src/headers/json_parser.h
    src/headers/data.h
    src/headers/json_parser.h

    )

# Связать с библиотеками Qt
#target_link_libraries(${PROJECT_NAME} Qt6::Widgets)
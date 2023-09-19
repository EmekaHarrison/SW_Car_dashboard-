cmake_minimum_required(VERSION 3.22)

project(teamwork LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QT_LIBRARIES_CL Qt6::Core Qt6::Widgets)
set(QT_LIBRARIES_SV Qt6::Core Qt6::Widgets)


set(CLIENT_DIR client/desktop)
set(CLIENT_HEADERS shared/setting.h ${CLIENT_DIR}/include/window.h ${CLIENT_DIR}/include/canvas.h ${CLIENT_DIR}/include/comservice.h ${CLIENT_DIR}/include/tcpservice.h)
set(CLIENT_SOURCES ${CLIENT_DIR}/main.cpp ${CLIENT_DIR}/src/window.cpp ${CLIENT_DIR}/src/canvas.cpp ${CLIENT_DIR}/src/comservice.cpp ${CLIENT_DIR}/src/tcpservice.cpp)


set(SERVER_DIR server/desktop)
set(SERVER_HEADERS shared/setting.h ${SERVER_DIR}/include/dialog.h ${SERVER_DIR}/include/comservices.h ${SERVER_DIR}/include/tcpservices.h)
set(SERVER_SOURCES ${SERVER_DIR}/main.cpp ${SERVER_DIR}/src/dialog.cpp ${SERVER_DIR}/src/comservices.cpp ${SERVER_DIR}/src/tcpservices.cpp)


find_package(Qt6 CONFIG REQUIRED COMPONENTS Core Widgets)


add_executable(client ${CLIENT_HEADERS} ${CLIENT_SOURCES})
target_link_libraries(client PUBLIC ${QT_LIBRARIES_CL} )
target_include_directories(client PUBLIC shared ${CLIENT_DIR}/include)


add_executable(server ${SERVER_HEADERS} ${SERVER_SOURCES})
target_link_libraries(server PUBLIC ${QT_LIBRARIES_SV} )
target_include_directories(server PUBLIC shared ${SERVER_DIR}/include)


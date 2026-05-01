cmake_minimum_required(VERSION 3.22)
set(PROJECT_NAME hornet-bot)
set(PROJECT_VERSION 0.1)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})
set(SOURCE
	src/main.cxx
	src/bot/bot.cxx
	src/commands/ping.cxx
)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

add_executable(${PROJECT_NAME} ${SOURCE})
find_package(DPP REQUIRED)
target_link_libraries(${PROJECT_NAME} ${DPP_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${DPP_INCLUDE_DIR})

set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
)

project(lssql)

cmake_minimum_required(VERSION 3.10)

add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

aux_source_directory(src/ls/sql SRC)
aux_source_directory(sample SRC_SAMPLE)

include_directories(src)

add_library(lssql SHARED ${SRC})

add_executable(testcase ${SRC} ${SRC_SAMPLE})

target_link_libraries(testcase lsconfig lsjson lsutil mysqlcppconn lsorderedmap)

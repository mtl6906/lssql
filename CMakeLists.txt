project(lssql)

cmake_minimum_required(VERSION 3.10)

add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

aux_source_directory(src/ls/sql SRC)
aux_source_directory(sample SRC_SAMPLE)

include_directories(include)

add_library(lssql SHARED ${SRC})

add_executable(testcase ${SRC} ${SRC_SAMPLE})

target_link_libraries(testcase lsconfig lsjson lsitem lslogger lsbuffer lsio lsfile lsexception lscstring lstime  lscopyableitem mysqlcppconn)

install(TARGETS lssql DESTINATION lib)

install(DIRECTORY include/ls/sql DESTINATION include/ls)


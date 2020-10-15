# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)
# 项目信息
project (1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS} -std=c++11")
FIND_PACKAGE(Threads REQUIRED)
FIND_PACKAGE(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS system thread)

message(STATUS "OpenCV library status:")
message(STATUS "opencv_version: ${OpenCV_VERSION}")
message(STATUS "opencv_libraries: ${OpenCV_LIBS}")
message(STATUS "opencv_include path: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "boost library status:")
message(STATUS "boost_version: ${Boost_VERSION}")
message(STATUS "boost_libraries: ${Boost_LIBS}")
message(STATUS "boost_include path: ${Boost_INCLUDE_DIRS}")
message(STATUS　"thread library status:" )
message(STATUS　"thread_version:" )
message(STATUS　"thread_libraries:" )
message(STATUS　"thread_include path:" )
# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)
# 添加头文件路径
include_directories(${Boost_INCLUDE_DIRS})
#find_package(OpenCV REQUIRED)   
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(./ ./serial ./aromr)
#include_directories("${PROJECT_SOURCE_DIR}/armor")
#include_directories("${PROJECT_SOURCE_DIR}/serial")
# 添加子目录
add_subdirectory(armorDetect)
add_subdirectory(serial)
# 指定生成目标
add_executable(1 ${DIR_SRCS})
# 添加链接库
target_link_libraries(1 armorDetect serial -lboost_system -lpthread -lX11 ${OpenCV_LIBS} ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

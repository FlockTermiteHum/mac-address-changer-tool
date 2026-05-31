cmake_minimum_required(VERSION 3.10)
project(MacAddressChangerTool)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS system)

add_executable(mac_changer src/main.cpp src/mac_changer.cpp src/network_utils.cpp)
target_link_libraries(mac_changer PRIVATE Boost::system)
target_include_directories(mac_changer PRIVATE include)

enable_testing()
add_subdirectory(tests)
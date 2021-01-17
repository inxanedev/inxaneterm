cmake_minimum_required(VERSION 3.10)
project(inxaneterm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED IMPORTED_TARGET gtkmm-3.0)
pkg_check_modules(VTE REQUIRED IMPORTED_TARGET vte-2.91)

add_executable(inxaneterm
    "src/main.cc"
    "src/main_window.cc"
)

target_include_directories(inxaneterm PRIVATE "./src/")
target_link_libraries(inxaneterm PUBLIC
    PkgConfig::GTKMM
    PkgConfig::VTE
)

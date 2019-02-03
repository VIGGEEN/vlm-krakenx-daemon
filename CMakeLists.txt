cmake_minimum_required(VERSION 3.13)
project(vlm-krakenx-daemon)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(
        "-Wall" "-Wpedantic" "-Wextra" "-fexceptions"
        "-O3"
)

find_path(LM_SENSORS_INCLUDE_DIR NAMES sensors/sensors.h)
find_library(LM_SENSORS_LIBRARY NAMES libsensors sensors)

set(LM_SENSORS_LIBRARIES ${LM_SENSORS_LIBRARY})
set(LM_SENSORS_INCLUDE_DIRS ${LM_SENSORS_INCLUDE_DIR})

add_executable(vlm-krakenx-daemon main.cpp LinearFunc.cpp LinearFunc.h KrakenXConfig.cpp KrakenXConfig.h CpuPackageTemp.cpp CpuPackageTemp.h)

target_link_libraries(vlm-krakenx-daemon ${LM_SENSORS_LIBRARY})
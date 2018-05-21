# Libraries:

link_libraries (gcc)

include_directories (src/)

set (hwlib ${build_environment}/libraries/hwlib)
include_directories (${hwlib}/library)

set (catch ${build_environment}/libraries/Catch2)
include_directories (${catch}/single_include)

# Source Files:

set (sources
    src/wrap-hwlib.cpp
    src/libc-stub.cpp
    src/lidar_mini.cpp
    src/filter.cpp
    src/uart_protocol.cpp
)

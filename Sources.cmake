# Libraries:

link_libraries (gcc)

set (hwlib ${build_environment}/libraries/hwlib)
include_directories (${hwlib}/library)

set (catch ${build_environment}/libraries/Catch2)
include_directories (${catch}/single_include)

# Source Files:

set (sources
    src/libc-stub.cpp
    src/filter.cpp
    src/lidar_mini.cpp
    src/uart_connection.cpp
    src/uart_protocol.cpp
    src/uart_connection.cpp
)

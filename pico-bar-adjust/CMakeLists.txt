cmake_minimum_required(VERSION 3.12)

# Pull in PICO SDK (must be before project)
include(pico_sdk_import.cmake)

# We also need PICO EXTRAS
#include(pico_extras_import.cmake)

# We also need Pimoroni
include(pimoroni_pico_import.cmake)

project(baradjust C CXX)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DPICO_USE_STACK_GUARDS=1")

# Initialize the Pico SDK
pico_sdk_init()

add_executable(baradjust
    main.cpp
    mcp3428.cpp
)

include(common/pimoroni_i2c)
include(common/pimoroni_bus)
include(drivers/st7789/st7789)
include(libraries/pico_graphics/pico_graphics)

pico_enable_stdio_usb(baradjust 0)
pico_enable_stdio_uart(baradjust 0)

target_link_libraries(baradjust PRIVATE pico_multicore pico_stdlib hardware_pwm hardware_spi hardware_dma hardware_pio hardware_i2c st7789 pico_graphics)
pico_add_extra_outputs(baradjust)

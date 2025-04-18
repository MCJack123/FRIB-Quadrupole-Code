# FRIB-Quadrupole-Code

## ECE480-Distribution.X
MPLAB X project for microcontroller on the distribution board.

### Building
Use [MPLAB X](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide) with XC8 to build the project. The built HEX file will be in `dist/default/production/ECE480-Distribution.X.production.hex`.

### Flashing
The board has Microchip ICSP capabilities for programming. Use the following pin assignments to connect to an ICSP programmer:
| ICSP pin | Qw/ST pin |
|----------|-----------|
| Vdd      | 3.3V      |
| Vss      | GND       |
| ICSPDAT  | SDA       |
| ICSPCLK  | SCL       |
| Vpp/MCLR | JP1 (side closer to MCU) |

Note that MCLR connects directly to the JP1 jumper pad, which must not be bridged.

Programming may be done with an official Microchip PICkit or ICD 4 or 5. If you don't have one available, you can use a Raspberry Pi Pico running [this programmer firmware](https://github.com/MCJack123/pico-icsp-programmer). To use, build and upload the program, connect the pins as directed, and simply send the HEX file over the serial connection that appears.

## pico-bar-adjust
Demo program for a frontend with 8 bars, sending 3-bit signals over I2C. Not the final interface.

Requires a Raspberry Pi Pico mounted on a [Pimoroni Pico Display Pack 2.8"](https://shop.pimoroni.com/products/pico-display-pack-2-8). Building requires the Pico SDK, Pico SDK Extras, and Pimoroni Pico libraries.

Use buttons A/B to select the row, and X/Y to adjust the value.

## pico-i2c-driver
Final program to adapt USB serial data to I2C. Use CMake and the Pico SDK to build. Flash the built UF2 using the BOOT button.

## Initial-Distribution-Board
KiCAD PCB files for the first design of the distribution board, before integration with the power splitter and phase shifter. Production files for JLCPCB are included in `production/`.

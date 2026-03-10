# MiiPad

PIC HERE

The MiiPad is a 12 key custom keypad made with mechanical switches, a magnetic case, and a microcontroller. It's fully programmable, supports multi-layer, tap/hold control, and even full on macros.

## Parts

- 1x 3D Printed Case
- 1x Custom PCB
- 1x Microcontroller Board (Xiao RP2040)
- 12x Diodes (SOD-123)
- 12x MX Style Mechanical Switches (Cherry MX Browns)
- 12x MX Style Keycaps (Extras, to your preference is fine)

## Tools

- 3D Printer
- Soldering Iron
- Solder
- Flux
- KiCad
- Blender
- QMK
  
## Process

1. Part Picking
2. PCB Design
3. Case Design
4. Soldering
5. Firmware Configuration

## PCB - Schematic
Making a PCB comes in 2 parts, the schematic, and the design; I did both in KiCad, as it's a popular and free PCB design software.

The schematic is a file comprised of everything your PCB will have: microcontroller, diodes, connections, coated cutouts. Make sure the things that need to be connected are connected via the wire tool, or global labels. Each thing in your schematic comes in the form of a symbol, and most of the time there is a footprint attached to it. Footprints will be used later to make the design.

Earlier I picked out a 4x3 matrix for the layout, so that will be created with 12 switch symbols, alongside a diode symbol for each one. Under each row of switches, there will be a horizontal wire that is connected to the ends of each diode in that row, the same applies with a vertical wire and each column.


## PCB - Design
The design is where everything is laid out, the design will be a 1 to 1 of the actual PCB, so it is very important that everything is at the right place. The items come as the footprints attached to the symbols used in the schematic, each foodprint represents the actual marking/cutout that will be on the PCB.

I had to recreate the 4x3 matrix that was made in the schematic, paired with each switch in the matrix is the diode corresponding to it. Making sure they are lined up correctly so wiring them would be simpler and more organized. The microcontroller sits on the top with 4 pins connected to rows, and 3 connected to columns.


## Case

## Soldering

## Firmware - QMK
Instead of making my owm firmware from scratch, there is a firmware called QMK that is popular within the mechanical keyboard market/community.

## Extras

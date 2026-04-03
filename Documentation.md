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
  
## Workflow

1. Part Picking
2. PCB Design
3. Case Design
4. Soldering
5. Firmware Configuration

## PCB - Schematic
Making a PCB comes in 2 main parts, the schematic, and the design. I did both in KiCad, as it's a popular and free PCB design tool.

The schematic is a file comprised of everything your PCB will have: microcontroller, diodes, and connections. In KiCad, each thing in your schematic comes in the form of a symbol, and most of the time linked to a footprint, which will be used later. These symbols are them connected with the wiring tool

Earlier I picked out a 4x3 matrix for the layout, so that will be created with 12 switch symbols, alongside a diode symbol for each one. Under each row of switches, there will be a horizontal wire that is connected to the ends of each diode in that row, the same applies with a vertical wire and each column.


## PCB - Design
The design is where everything is laid out, the design will be a 1:1 of the actual PCB, placement and dimensions need to be accurate. The items come as the footprints attached to the symbols used in the schematic, each footprint represents a marking or cutout on the PCB.

I had to make the 4x3 matrix that was made in the schematic, paired with each switch in the matrix is the diode corresponding to it. Making sure they are lined up correctly so wiring them would be simpler and more organized. The microcontroller sits on the top with 4 pins connected to rows, and 3 connected to columns.


## Case
The case was made in Blender, any 3D modeling software can work, but it's free and something I had a little bit of prior experience with so it was my first pick. Typically keyboard cases are broken down into 3 components: top, bottom, and plate. The plate is actually not required for soldered on switches, but I decided to include it because it gives the keypad some more rigidity.

The overall design is very minimal, just a rectangle with some beveling so it doesn't feel sharp. Actually modeling it was not so simple because I decided to merge the plate and the housing to make soldering later easier. Fusing the walls and plate into one meant the dimensions would have to be extra precise, as with pieces so small, a single milimeter difference could cause problems. The bottom is just a duplicate of the top, but rotated, holes filled, and shortened.

Towards the end I decided magnets would be better than just gluing the 2 halves together, this lets me have a solid case with the ability to open it in case I need to replace any of the switches or if something just breaks in general. The magnets were 2x2x2mm cylinders, which fit perfectly in the corners of my 4mm thick walls. Both models have a 2x2x2mm cylinder hole in each of the 4 corners.

## Soldering
There's not that much to soldering, the only important thing to take note is finding a stable workspace with decent air ventilation. I ended up doing it in my room right next to a window with a fan sucking the fumes straight outside. The only real issue I had was soldering the diodes, as the extremely small size gave me some trouble, but a pair of tweezers and patience got the job done.

## Firmware - QMK
Instead of making my owm firmware from scratch, there is an open source firmware called QMK. QMK is fairly popular in the custom keyboard market/community because of it's ease of use, it also has supporting software built on top of it like VIA and VIAL, which are both interfaces that make configuring your own keyboard even easier. In this project I stuck with QMK because I did not have a real need for further customization, and with QMK I was able to:
1. Register the keypad as it's own device
2. Register 12 unique inputs.
3. Allow for multiple layers of outputs
4. Support macro keys

QMK provides the 2 main files needed, config.h and keymap.c files.
- config.h sets the rules for your keypad:debounce, registration time.
- keymap.c is where the actual keys are programmed.

They provide a [list of pre-made keycodes](https://docs.qmk.fm/keycodes), these go from single letters to layer control.



## Resources

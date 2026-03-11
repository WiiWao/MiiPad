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
Making a PCB comes in 2 parts, the schematic, and the design; I did both in KiCad, as it's a popular and free PCB design software.

The schematic is a file comprised of everything your PCB will have: microcontroller, diodes, connections, coated cutouts. Make sure the things that need to be connected are connected via the wire tool, or global labels. Each thing in your schematic comes in the form of a symbol, and most of the time there is a footprint attached to it. Footprints will be used later to make the design.

Earlier I picked out a 4x3 matrix for the layout, so that will be created with 12 switch symbols, alongside a diode symbol for each one. Under each row of switches, there will be a horizontal wire that is connected to the ends of each diode in that row, the same applies with a vertical wire and each column.


## PCB - Design
The design is where everything is laid out, the design will be a 1 to 1 of the actual PCB, so it is very important that everything is at the right place. The items come as the footprints attached to the symbols used in the schematic, each foodprint represents the actual marking/cutout that will be on the PCB.

I had to recreate the 4x3 matrix that was made in the schematic, paired with each switch in the matrix is the diode corresponding to it. Making sure they are lined up correctly so wiring them would be simpler and more organized. The microcontroller sits on the top with 4 pins connected to rows, and 3 connected to columns.


## Case
The case was made in blender, any 3D modeling software can work, but it was free and something I had a little bit of prior experience with so it was my first pick. Typically keyboard cases are broken down into 3 components: top, bottom, and plate. The plate is actually not required for soldered on switches, but I decided to include it because it gives the keypad some more rigidity.

The overall design is very minimal, just a rectangle with some beveling so it doesn't feel sharp. Actually modeling it was not so simple. I decided to merge the plate and the housing to make soldering later easier, however this made 3d modeling a bit harder. Instead of just making a case, I had to make sure the measurements of where the switches would be, the pcb, the microcontroller usb-c connections, and the usb-c cutout would all match up. I had to find a model of both the switches and the microcontroller board to make sure the dimensions of the top case was correct. Next is the bottom half, but it was made with just duplicating the top, filling the holes, and then chopping a good portion of it off(it's 1/5 the height of the top).

Initially the top and bottom were to be super glued on, but I decided to use magnets to hold the top and bottom together. This would allow me to open the case up incase a switch broke or I find out my soldering is not the best. I would just add 4 holes (2x2x1mm) into the top and bottom housing, 1 in each corner. I ran into one problem with this, which is that the corner walls were not thick enough, so I just made it thicker. However this made me realized an extremely big problem, originally my walls were 1mm thick, which is way too thin for the 3D printer I have, generally not recommended for a print like this, and it poses a risk of being too fragile if I were to bring this keypad around. The walls were shortly made to be 4mm wide instead, which fits well with the corner magnets.

## Soldering
Not much to say here other than to know what you're doing and using. Prepare a decently sized flat top somewhere with good ventilation, keep things organized, and apply flux as needed. I ended up having to resolder the microcontroller and a diode because they were trickier to work due to them being flat on the board, compared to the switches poking out from the other side. Another plus of having the top part being one joint piece is that you can snap the switches into place, then flip it around and solder it without them popping off the pcb or having to re-align them.

## Firmware - QMK
Instead of making my owm firmware from scratch, there is an open source firmware called QMK. QMK is fairly popular in the custom keyboard market/community because of it's ease of use, it also has supporting software built on top of it like VIA and VIAL, which are both interfaces that make configuring your own keyboard even easier. In this project I stuck with QMK because I did not have a real need for further customization, and with QMK I was able to:
1. Register the keypad as it's own device
2. Register 12 unique inputs.
3. Allow for multiple layers of outputs
4. Support macro keys

QMK provides the 2 main files needed, config.h and keymap.c files.
config.h sets the rules for your keypad:debounce, registration time.  
keymap.c is where the actual keys are programmed.

They provide a [list of pre-made keycodes](https://docs.qmk.fm/keycodes), these go from single letters to layer control.



## Extras

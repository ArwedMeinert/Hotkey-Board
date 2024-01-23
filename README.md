# Hotkey-Board
All the needed Information for the Hotkey-Board
It includes the Schematics of the Hardware, the PCB- Layout and the Code for the actual microcontroller. 
Feel free to make your own changes and improve on what’s already there. 
All the uploaded Files (excluding the libraries in the Arduino IDE) were created by me.

After the design of the PCB, I got it made and soldert all parts on it. Luckily, everything worked at the first try.

<img src="https://github.com/ArwedMeinert/Hotkey-Board/blob/main/Hotkey-board/IMG_20220221_132830_472.jpg" alt= "The PCB of the Hotkey Board" width="50%" height="50%" >

Each button can be individually programmed. You can add more than one profile and add an individual colour to each profile (every button is individually backlit and be individually addressed). A button press gets visualized by the sudden change of colour, that then fades back to the standard colour of the profile within 200 ms (this also helps with the debounce time of the buttons).

<img src="https://github.com/ArwedMeinert/Hotkey-Board/blob/main/Hotkey-board/IMG_20221215_135644_090.jpg" alt= "The PCB of the Hotkey Board" width="50%" height="50%" >

This version of the Hotkey-Board doesn't support anti-ghosting (using diodes for the button matrix). This could be an improvement left for a second version as well as a little OLED display to display various functions of the keys. 
## Case
After a few months in use I descided to add a case for the pcb to make it easier to carry around (and because I got access to a 3D Printer).

<img src="https://github.com/ArwedMeinert/Hotkey-Board/blob/main/Pictures/GOPR0397_ALTA329636650034166083.JPG" alt= "Case of the Board" width="50%" height="50%" >

All the files are available to download. The case now also includes holes for the hinges as well as magnets embedded in the lid to make it stay closed but still easy enough to open.

<img src="https://github.com/ArwedMeinert/Hotkey-Board/blob/main/Pictures/GOPR0398_ALTA329636650034166083.JPG" alt= "Case with the Board turned on" width="50%" height="50%" >


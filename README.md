# Transport_Control
Transport Control is a project for controlling the Transport functions of a DAW. Originally this project was created to allow me to record vocals further from my computer keyboard. Ultimately I would have to press the 'r' key to record, press 'space' to stop, and depending on the quality of the take I also wanted to be able to send 'ctrl+z' to undo, or effeectively delete the recording.

After creating the basic sketch I realized that there may be other uses for the Transport control beyond my limited implementation. 

Most other transport control projects send MIDI CC signals to the host machine. This is approach is probably better in a lot of cases:
	Focus needs to be on the DAW for this project to work, MIDI probably doesn't have this problem. 
	Midi is more widely implemented and the messages are standardized. For this project hotkeys need to be hardcoded for the exact purpose.

Despite these shortcomings I still like this project due to its simplicity. If you know your keyboard shortcut, you know exactly what you need to emulate. 

I do not intend to use this project as a means to send MIDI CC messages. I think this would go beyond the scope of my "simple solution" to this problem.

4/16/2021
The first draft of this code was not extensible, it read more like a script. I am intending to create a button object/struct and an array to hold all of these objects for later iteration. This way users can define how many buttons their project will have, each buttons debounce time, and the key stroke(s) associated with the button.
-- later that day
Refactored so that each button is a struct with key and keymod fields. The keymod is pressed before the key, such as control, alt, shift. The keymod is a constant int as defined by the Keyboard library. Keys are single chars. 
This way the button handler code isn't 3 near identical blocks, but a single block that can handle any of the objects as defined. 
Users should be able to easily add/remove buttons, tweak their hotkeys, and debounce times. 
For my purposes the debounce times are High as I want to avoid multiple keystrokes and I'm using it as a footswitch. For other projects you may want to reduce the debounce time for rapid keystrokes or perhaps game controllers.

At this point I think the project is "complete" if anyone really wants to change something or notices a bug/error feel free to reach out to me at j@onesadpuppy.com



# Transporti_Control
Transport Control is a project for controlling the Transport functions of a DAW. Originally this project was created to allow me to record vocals further from my computer keyboard. Ultimately I would have to press the 'r' key to record, press 'space' to stop, and depending on the quality of the take I also wanted to be able to send 'ctrl+z' to undo, or effeectively delete the recording.

After creating the basic sketch I realized that there may be other uses for the Transport control beyond my limited implementation. 

Most other transport control projects send MIDI CC signals to the host machine. This is approach is probably better in a lot of cases:
	Focus needs to be on the DAW for this project to work, MIDI probably doesn't have this problem. 
	Midi is more widely implemented and the messages are standardized. For this project hotkey need to be hardcoded for the exact purpose.

Despite these shortcomings I still like this project due to its simplicity. If you know you're keyboard shortcut, you know exactyl what you need to emulate. 

The first draft of this code was not extensible, it read more like a script. I am intending to create a button object/struct and an array to hold all of these objects for later iteration. This way users can define how many buttons their project will have, each buttons debounce time, and the key stroke(s) associated with the button.

I do not intend to use this project as a means to send MIDI CC messages. I think this would go beyond the scope of my "simple solution" to this problem.


#include <Keyboard.h>

//Footswitch struct is the main 'object' in this project.
/*
  pin is the ditigal pin on the board
  state is the HIGH/LOW reading
  lastTimePressed and debounceTime are used to protect from "double presses"
  key is the character key to press
  keymod is the key modifier, shift, alt, control
*/
struct Footswitch {
  int pin;
  int state;
  unsigned long lastTimePressed;
  unsigned long debounceTime;
  char key;
  int keymod;
};

const int num_switches = 3; //how many buttons do you want?

//here we define the buttons, each field is defined in order based on the struct above
Footswitch playButton = {3, 0, 0, 500, ' ', 0};
Footswitch undoButton = {4, 0, 0, 1000, 'z', KEY_LEFT_CTRL};
Footswitch recButton = {5, 0, 0, 1000, 'r', 0};

//create an array of switches, this will be populated with the buttons we created above
Footswitch switchList[num_switches];


void setup() {
  //populate our list of switches with the switches we defined above
  switchList[0] = playButton;
  switchList[1] = undoButton;
  switchList[2] = recButton;

  //loop to set all of the buttons in our list to input pullup
  for (int i = 0; i < num_switches; i++) {
    pinMode(switchList[i].pin, INPUT_PULLUP);
  }

  //Keyboard library needs to be "initialized"
  Keyboard.begin();
}

void loop() {
  for (int i = 0; i < num_switches ; i++) {
    //Read button states, LOW means button is pressed
    switchList[i].state = digitalRead(switchList[i].pin);

    if (switchList[i].state == LOW) {
      // debounce check ensures only one press per debounce time (1000ms = 1 sec)
      if ((millis() - switchList[i].lastTimePressed) > switchList[i].debounceTime) {
        if (switchList[i].keymod == 0) {
          //if there is no keymod, send keyboard event
          Keyboard.press(switchList[i].key);
        } else {
          //if there is a keymod, press that first, then the key
          Keyboard.press(switchList[i].keymod);
          Keyboard.press(switchList[i].key);
        }
        //release all keys, ensure that our emulated keyboard isn't holding down keys
        Keyboard.releaseAll();
        //update the button's last time pressed to the current time
        switchList[i].lastTimePressed = millis();
      }
    }
  }
}

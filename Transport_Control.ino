#include <Keyboard.h>

struct Footswitch {
  int pin;
  int state;
  unsigned long lastTimePressed;
  unsigned long debounceTime;
  char key;
  int keymod;
};

const int num_switches = 3;
Footswitch playButton = {3, 0, 0, 500,' ',0};
Footswitch undoButton = {4, 0, 0, 1000,'z', KEY_LEFT_CTRL};
Footswitch recButton = {5, 0, 0, 1000,'r', 0};

Footswitch switchList[num_switches];


void setup() {
  switchList[0] = playButton;
  switchList[1] = undoButton;
  switchList[2] = recButton;

 for (int i =0; i< num_switches; i++){
  pinMode(switchList[i].pin, INPUT_PULLUP);
 }
 
  Keyboard.begin();
}

void loop() {

  //Read button states, LOW means button is pressed
 for (int i=0; i < num_switches ; i++){
  switchList[i].state = digitalRead(switchList[i].pin);

  if (switchList[i].state == LOW){
    // debounce check ensures only one press per debounce time (1000ms = 1 sec)
    if ((millis() - switchList[i].lastTimePressed) > switchList[i].debounceTime) {
      //send keyboard event
      if (switchList[i].keymod ==0){
         Keyboard.press(switchList[i].key);
      }else{
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

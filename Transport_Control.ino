#include <Keyboard.h>

struct footswitch {
  int pin;
  int state;
  unsigned long lastTimePressed;
  unsigned long debounceTime;
};

footswitch playButton = {3, 0, 0, 500};
footswitch undoButton = {4, 0, 0, 1000};
footswitch recButton = {5, 0, 0, 1000};

void setup() {
  pinMode(playButton.pin , INPUT_PULLUP);
  pinMode(undoButton.pin , INPUT_PULLUP);
  pinMode(recButton.pin , INPUT_PULLUP);

  Keyboard.begin();
}

void loop() {

  //Read button states, LOW means button is pressed
  playButton.state = digitalRead(playButton.pin);
  undoButton.state = digitalRead(undoButton.pin);
  recButton.state = digitalRead(recButton.pin);

  if (playButton.state == LOW) {
    // debounce check ensures only one press per debounce time (1000ms = 1 sec)
    if ((millis() - playButton.lastTimePressed) > playButton.debounceTime) {
      //send keyboard event
      Keyboard.press(' ');
      //release all keys, ensure that our emulated keyboard isn't holding down keys
      Keyboard.releaseAll();
      //update the button's last time pressed to the current time
      playButton.lastTimePressed = millis();
    }
  }
  // following buttons follow same logic as the play button
  if (undoButton.state == LOW) {
    if ((millis() - undoButton.lastTimePressed) > undoButton.debounceTime) {
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('z');
      Keyboard.releaseAll();
      undoButton.lastTimePressed = millis();
    }
  }
  if (recButton.state == LOW) {
    if ((millis() - recButton.lastTimePressed) > recButton.debounceTime) {
      Keyboard.press('r');
      Keyboard.releaseAll();
      recButton.lastTimePressed = millis();
    }
  }

}

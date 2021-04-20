/*
  ZoomMuter

  When you connect pin 2 to ground, it performs a logout.
  It uses keyboard combinations to do this, as follows:

  On Windows, CTRL-ALT-DEL followed by ALT-l
  On Ubuntu, CTRL-ALT-DEL, and ENTER
  On OSX, CMD-SHIFT-q
*/

#define OSX 0
#define WINDOWS 1
#define UBUNTU 2

#include "Keyboard.h"
#include <Button.h>

// change this to match your platform:
int platform = OSX;

int mutePin = 2;
int videoPin = 3;

// Set up buttons, 10ms debounce
Button muteButton(mutePin, 10); // Connect your button between pin 2 and GND
Button videoButton(videoPin, 10); // Connect your button between pin 3 and GND

void setup() {
  // make the two button pins inputs and turn on the pull-up resistor so it goes high unless
  // connected to ground:
  muteButton.begin();
  videoButton.begin();

  Keyboard.begin();
}

void loop() {
  if (muteButton.pressed()) {
    Serial.println("mute button pressed");
    muteUnmute();
  }

  if (videoButton.pressed()) {
    Serial.println("video button pressed");
    startStopVideo();
  }
}

void muteUnmute() {
  switch (platform) {
    case OSX:
      // Command-Shift-A mutes audio
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('A');
      delay(100);
      Keyboard.releaseAll();
      break;
    case WINDOWS:
      break;
    case UBUNTU:
      break;
  }
}

void startStopVideo() {
  switch (platform) {
    case OSX:
      // Command-Shift-A mutes audio
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('V');
      delay(100);
      Keyboard.releaseAll();
      break;
    case WINDOWS:
      break;
    case UBUNTU:
      break;
  }
}

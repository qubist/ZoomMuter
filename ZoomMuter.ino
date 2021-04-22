/*
  ZoomMuter

  When you connect pin 2 to ground, it performs a logout.
  It uses keyboard combinations to do this, as follows:

  On Windows, CTRL-ALT-DEL followed by ALT-l
  On Ubuntu, CTRL-ALT-DEL, and ENTER
  On OSX, CMD-SHIFT-q
*/

#define MACOS 0
#define WINDOWS 1
#define UBUNTU 2

#include "Keyboard.h"
#include <Button.h>

// Variable to keep track of what platform the device is set for
int platform;

const int mutePin = 2;
const int videoPin = 3;

const int ubuntuPin = 5;
const int windowsPin = 6;

// Set up buttons, 10ms debounce
Button muteButton(mutePin, 10); // Connect your button between pin 2 and GND
Button videoButton(videoPin, 10); // Connect your button between pin 3 and GND

void setup() {
  // Begin the two buttons
  muteButton.begin();
  videoButton.begin();

  Keyboard.begin();

  // Initialize the OS switch's two pins
  pinMode(ubuntuPin, INPUT_PULLUP);
  pinMode(windowsPin, INPUT_PULLUP);

}

void loop() {

  // Check which OS mode we're on
  if (digitalRead(ubuntuPin) == LOW) {
    platform = UBUNTU;
  } else if (digitalRead(windowsPin) == LOW) {
    platform = WINDOWS;
  } else {
    platform = MACOS;
  }
  
  if (muteButton.pressed()) {
    Serial.println("mute button pressed");
    muteUnmute(platform);
  }

  if (videoButton.pressed()) {
    Serial.println("video button pressed");
    startStopVideo(platform);
  }
}

void muteUnmute(int platform) {
  switch (platform) {
    case MACOS:
      // Command-Shift-A mutes audio
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('A');
      delay(100);
      Keyboard.releaseAll();
      break;
    case WINDOWS:
      // FIXME
      break;
    case UBUNTU:
      // FIXME
      break;
  }
}

void startStopVideo(int platform) {
  switch (platform) {
    case MACOS:
      // Command-Shift-A mutes audio
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('V');
      delay(100);
      Keyboard.releaseAll();
      break;
    case WINDOWS:
      // FIXME
      break;
    case UBUNTU:
      // FIXME
      break;
  }
}

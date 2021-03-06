#include "trackball.h"

Trackball trackball;

#define COLOR_RED 0
#define COLOR_BLUE 1
#define COLOR_GREEN 2

int color;

void setup() {
  Serial.begin(9600);

  trackball.begin();
}

void loop() {
  trackball.upData();
  if (trackball.getX() || trackball.getY()) {
    Serial.print("x:");
    Serial.print(trackball.getX());
    Serial.print('\t');
    Serial.print("y:");
    Serial.println(trackball.getY());
  }

  if (trackball.getButtom()) {
    if (COLOR_RED == color) {
      trackball.SetLedColor(true, false, false);
      color = COLOR_BLUE;
    }
    else if (COLOR_BLUE == color) {
      trackball.SetLedColor(false, true, false);
      color = COLOR_GREEN;
    }
    else if (COLOR_GREEN == color) {
      trackball.SetLedColor(false, false, true);
      color = COLOR_RED;
    }
  }
  else if (!trackball.getButtomRaw()) {
    trackball.SetLedColor(false, false, false);
  }
}

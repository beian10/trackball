#include "trackball.h"

Trackball trackball;

int color;

void funFall()
{
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

void funRise()
{
  trackball.SetLedColor(false, false, false);
}

void setup() {
  Serial.begin(9600);

  trackball.begin();
  trackball.attachKey(FALL_MODE, funFall);
  trackball.attachKey(RISE_MODE, funRise);
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
}

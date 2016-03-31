#include <trackball.h>

Trackball trackball;

int color;

void funFall()
{
  if (COLOR_RED == color) {
    trackball.setLED(COLOR_RED, true);
    color = COLOR_BLUE;
  }
  else if (COLOR_BLUE == color) {
    trackball.setLED(COLOR_BLUE, true);
    color = COLOR_GREEN;
  }
  else if (COLOR_GREEN == color) {
    trackball.setLED(COLOR_GREEN, true);
    color = COLOR_RED;
  }
}

void funRise()
{
  trackball.setLED(COLOR_RED, false);
  trackball.setLED(COLOR_BLUE, false);
  trackball.setLED(COLOR_GREEN, false);
}

void setup() {
  Serial.begin(9600);

  trackball.begin();
  trackball.attachKey(FALL_MODE, funFall);
  trackball.attachKey(RISE_MODE, funRise);
}

void loop() {
  trackball.upDate();
  if (trackball.getX() || trackball.getY()) {
    Serial.print("x:");
    Serial.print(trackball.getX());
    Serial.print('\t');
    Serial.print("y:");
    Serial.println(trackball.getY());
  }
}

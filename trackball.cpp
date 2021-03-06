#include "trackball.h"

Trackball::Trackball()
{
  pinValue = 0xFF;
  lastPinValue = 0xFF;

  pRiseFunc = NULL;
  pFallFunc = NULL;

}

void Trackball::begin()
{
  Wire.begin();
  pinValue = readPin();
  witerPin(0xFF);

}

uint8_t Trackball::readPin()
{
  uint8_t pin;
  int32_t n = 500;
  Wire.requestFrom((uint8_t) 0x20, (uint8_t) 0x01);
  while (Wire.available() < 1 && n--)
    ;
  pin = Wire.read();

  return pin;
}

void Trackball::witerPin(uint8_t _pin)
{
  Wire.beginTransmission(0x20);
  Wire.write(_pin);
  Wire.endTransmission();
}

void Trackball::upData()
{
  lastPinValue = pinValue;

  pinValue = readPin();

  _x = 0;
  _y = 0;

  if (bitRead(lastPinValue, 0) != bitRead(pinValue, 0)) _x++;
  if (bitRead(lastPinValue, 2) != bitRead(pinValue, 2)) _x--;

  if (bitRead(lastPinValue, 1) != bitRead(pinValue, 1)) _y++;
  if (bitRead(lastPinValue, 3) != bitRead(pinValue, 3)) _y--;

  if ( NULL != pRiseFunc &&
       !bitRead(lastPinValue, 4) &&
       bitRead(pinValue, 4)) {
    (*pRiseFunc)();
  }

  if ( NULL != pFallFunc &&
       bitRead(lastPinValue, 4) &&
       !bitRead(pinValue, 4)) {
    (*pFallFunc)();
  }

}


void Trackball::attachKey(uint16_t _mode, void _pfunc(void) )
{
  if (RISE_MODE == _mode) pRiseFunc = _pfunc;
  else if (FALL_MODE == _mode) pFallFunc = _pfunc;
}

int16_t Trackball::getX()
{
  return _x;
}

int16_t Trackball::getY()
{
  return _y;
}

uint8_t Trackball::getKey()
{
  return bitRead(pinValue, 4);
}

void Trackball::SetLedColor(bool R, bool G, bool B)
{
  bitWrite(pinValue, 5, (!R)) ;
  bitWrite(pinValue, 6, (!G));
  bitWrite(pinValue, 7, (!B));

  witerPin(pinValue | 0x1F);
}

bool Trackball::getButtomRaw()
{
  return bool(!bitRead(pinValue, 4));
}

bool Trackball::getButtom()
{
  return bool(bitRead(lastPinValue, 4) && !bitRead(pinValue, 4));
}

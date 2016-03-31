// 本作品采用知识共享 署名-非商业性使用-相同方式共享 3.0 未本地化版本 许可协议进行许可
// 访问 http://creativecommons.org/licenses/by-nc-sa/3.0/ 查看该许可协议
// ==============

// 版权所有：
// jiale
// jialexd@foxmail.com
// ==============

// Microduino-IDE
// ==============
// Microduino Getting start:
// http://www.microduino.cc/download/

// Microduino IDE Support：
// https://github.com/wasdpkj/Microduino-IDE-Support/

// ==============
// Microduino wiki:
// http://wiki.microduino.cc

// ==============
// E-mail:
// jiale
// jialexd@foxmail.com

#ifndef TRACKBALL_H
#define TRACKBALL_H

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <Wire.h>

#define RISE_MODE 0
#define FALL_MODE 1

#define COLOR_RED 0
#define COLOR_GREEN 1
#define COLOR_BLUE 2

class Trackball {
  public:
    Trackball();
    void begin();
    void upDate();   //更新数据，需要放在loop()
    int16_t getX();		//获取x轴的数据
    int16_t getY();				//获取y轴的数据
    uint8_t getKey();		//获取按键值
    void attachKey(uint16_t _mode, void _pfunc(void) );		//设置按键电平上升沿或下降沿触发
    void setLED(uint16_t _color, bool _state);		//设置LED颜色
    
  private:
    uint8_t pinValue;
    uint8_t lastPinValue;
    int16_t _x;
    int16_t _y;
    void (*pRiseFunc)(void);
    void (*pFallFunc)(void);

    uint8_t readPin();
    void witerPin(uint8_t _pin);
    
};

#endif

#ifndef XPT2046_Bitbang_h
#define XPT2046_Bitbang_h

#include "Arduino.h"
#include <SPIFFS.h>


#ifndef TFT_WIDTH
#define TFT_WIDTH 320
#endif

#ifndef TFT_HEIGHT
#define TFT_HEIGHT 240
#endif

struct Point {
    int x;
    int y;
};

class XPT2046_Bitbang {
public:
    XPT2046_Bitbang(uint8_t mosiPin, uint8_t misoPin, uint8_t clkPin, uint8_t csPin);
    void begin();
    Point getTouch();
    void calibrate();
    bool loadCalibration();
    void saveCalibration();
    void setCalibration(int xMin, int yMin, int xMax, int yMax);

private:
    uint8_t _mosiPin;
    uint8_t _misoPin;
    uint8_t _clkPin;
    uint8_t _csPin;
    int readSPI(byte command);
    struct Calibration {
        int xMin;
        int xMax;
        int yMin;
        int yMax;
    } cal;
};

#endif

#ifndef _AMEBA_ILI9341_H_
#define _AMEBA_ILI9341_H_

#include "Print.h"
#include <cstdint>
#include "SPI.h"

#define ILI9341_TFTWIDTH     240
#define ILI9341_TFTHEIGHT    320

#define ILI9341_NOP         0x00
#define ILI9341_SWRESET     0x01
#define ILI9341_RDDID       0x04
#define ILI9341_RDDST       0x09

#define ILI9341_SLPIN       0x10
#define ILI9341_SLPOUT      0x11
#define ILI9341_PTLON       0x12
#define ILI9341_NORON       0x13

#define ILI9341_RDMODE      0x0A
#define ILI9341_RDMADCTL    0x0B
#define ILI9341_RDPIXFMT    0x0C
#define ILI9341_RDIMGFMT    0x0D
#define ILI9341_RDSELFDIAG  0x0F

#define ILI9341_INVOFF      0x20
#define ILI9341_INVON       0x21
#define ILI9341_GAMMASET    0x26
#define ILI9341_DISPOFF     0x28
#define ILI9341_DISPON      0x29

#define ILI9341_CASET       0x2A
#define ILI9341_PASET       0x2B
#define ILI9341_RAMWR       0x2C
#define ILI9341_RAMRD       0x2E

#define ILI9341_PTLAR       0x30
#define ILI9341_MADCTL      0x36
#define ILI9341_PIXFMT      0x3A

#define ILI9341_FRMCTR1     0xB1
#define ILI9341_FRMCTR2     0xB2
#define ILI9341_FRMCTR3     0xB3
#define ILI9341_INVCTR      0xB4
#define ILI9341_DFUNCTR     0xB6

#define ILI9341_PWCTR1      0xC0
#define ILI9341_PWCTR2      0xC1
#define ILI9341_PWCTR3      0xC2
#define ILI9341_PWCTR4      0xC3
#define ILI9341_PWCTR5      0xC4
#define ILI9341_VMCTR1      0xC5
#define ILI9341_VMCTR2      0xC7

#define ILI9341_RDID1       0xDA
#define ILI9341_RDID2       0xDB
#define ILI9341_RDID3       0xDC
#define ILI9341_RDID4       0xDD

#define ILI9341_GMCTRP1     0xE0
#define ILI9341_GMCTRN1     0xE1

#define ILI9341_MADCTL_MY   0x80
#define ILI9341_MADCTL_MX   0x40
#define ILI9341_MADCTL_MV   0x20
#define ILI9341_MADCTL_ML   0x10
#define ILI9341_MADCTL_RGB  0x00
#define ILI9341_MADCTL_BGR  0x08
#define ILI9341_MADCTL_MH   0x04

// Color definitions (RGB565)
#define ILI9341_BLACK       0x0000      /*   0,   0,   0 */
#define ILI9341_NAVY        0x000F      /*   0,   0, 128 */
#define ILI9341_DARKGREEN   0x03E0      /*   0, 128,   0 */
#define ILI9341_DARKCYAN    0x03EF      /*   0, 128, 128 */
#define ILI9341_MAROON      0x7800      /* 128,   0,   0 */
#define ILI9341_PURPLE      0x780F      /* 128,   0, 128 */
#define ILI9341_OLIVE       0x7BE0      /* 128, 128,   0 */
#define ILI9341_LIGHTGREY   0xC618      /* 192, 192, 192 */
#define ILI9341_DARKGREY    0x7BEF      /* 128, 128, 128 */
#define ILI9341_BLUE        0x001F      /*   0,   0, 255 */
#define ILI9341_GREEN       0x07E0      /*   0, 255,   0 */
#define ILI9341_CYAN        0x07FF      /*   0, 255, 255 */
#define ILI9341_RED         0xF800      /* 255,   0,   0 */
#define ILI9341_MAGENTA     0xF81F      /* 255,   0, 255 */
#define ILI9341_YELLOW      0xFFE0      /* 255, 255,   0 */
#define ILI9341_WHITE       0xFFFF      /* 255, 255, 255 */
#define ILI9341_ORANGE      0xFD20      /* 255, 165,   0 */
#define ILI9341_GREENYELLOW 0xAFE5      /* 173, 255,  47 */
#define ILI9341_PINK        0xF81F

class AmebaILI9341 : public Print {
    public:
        AmebaILI9341(int csPin, int dcPin, int resetPin, SPIClass& targetSPI = SPI);

        void begin(void);

        void setAddress(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);

        void writecommand(uint8_t command);
        void writedata(uint8_t data);
        void writedata(uint8_t *data, size_t datasize);

        void setRotation(uint8_t m);

        void fillScreen(uint16_t color);
        void clr();

        void fillRectangle(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
        void drawBitmap(int16_t x, int16_t y, int16_t w, int16_t h, const unsigned short *color);
        void drawPixel(int16_t x, int16_t y, uint16_t color);

        void drawChar(int16_t x, int16_t y, unsigned char c, uint16_t fontcolor, uint16_t background, uint8_t fontsize);
        void drawChar(unsigned char c);

        void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
        void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1);

        void drawRectangle(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
        void drawRectangle(int16_t x, int16_t y, int16_t w, int16_t h);

        void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
        void drawCircle(int16_t x0, int16_t y0, int16_t r);

        virtual size_t write(uint8_t);

        int16_t getWidth();
        int16_t getHeight();

        void setCursor(int16_t x, int16_t y);
        void setForeground(uint16_t color);
        void setBackground(uint16_t color);
        void setFontSize(uint8_t size);

    private:
        void reset(void);

        int _csPin;
        int _dcPin;
        int _resetPin;

        uint32_t _dcPort;
        uint32_t _dcMask;

        int16_t _width;
        int16_t _height;

        int16_t cursor_x;
        int16_t cursor_y;
        uint16_t foreground;
        uint16_t background;
        uint8_t fontsize;
        uint8_t rotation;
        SPIClass& _spi;
};

#endif

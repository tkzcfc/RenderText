#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>


#define NS_CC_BEGIN namespace cc {
#define NS_CC_END }

#ifndef CCAssert
#define CCAssert(cond, msg) ((void)(cond))
#endif  // CCAssert


#define CC_PLATFORM_WIN32 1
#define CC_TARGET_PLATFORM CC_PLATFORM_WIN32


struct DSize 
{
    float width;
    float height;

    DSize()
    {
        width = height = 0.0f;
    }

    DSize(float w, float h)
    {
        width = w;
        height = h;
    }
};

static const auto DSizeZero = DSize(0.0f, 0.0f);



struct DPoint
{
    float x;
    float y;

    DPoint()
    {
        x = y = 0.0f;
    }

    DPoint(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
};


struct DRect
{
    DPoint origin;

    DSize  size;

    DRect()
    {}
};


struct CAColor4B
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    CAColor4B()
    {
        r = g = b = a = 0;
    }

    CAColor4B(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a)
    {
        r = _r;
        g = _g;
        b = _b;
        a = _a;
    }


    static const CAColor4B BLACK;
};



struct CABitmapData
{
    unsigned char* data;
    uint32_t len;
    uint32_t width;
    uint32_t height;

    CABitmapData(unsigned char* data, uint32_t len, uint32_t width, uint32_t height)
    {
        this->data = data;
        this->len = len;
        this->width = width;
        this->height = height;
    }

    inline unsigned char getColorR(uint32_t x, uint32_t y)
    {
        uint32_t index = y * width + x;
        return data[index * 4];
    }

    inline unsigned char getColorG(uint32_t x, uint32_t y)
    {
        uint32_t index = y * width + x;
        return data[index * 4 + 1];
    }

    inline unsigned char getColorB(uint32_t x, uint32_t y)
    {
        uint32_t index = y * width + x;
        return data[index * 4 + 2];
    }

    inline unsigned char getColorA(uint32_t x, uint32_t y)
    {
        uint32_t index = y * width + x;
        return data[index * 4 + 3];
    }
};
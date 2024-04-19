#ifndef CAFont_Data_h__
#define CAFont_Data_h__


#include "CABase.h"
#include "CAFreeTypeFont.h"

NS_CC_BEGIN

struct FontDataTable
{
    std::string szFontName;
    int iFontSize;
    int iFontHeight;
    CAFreeTypeFont ftFont;
};


NS_CC_END

#endif // CAFont_Data_h__


#ifndef __CAFontProcesstor_H__
#define __CAFontProcesstor_H__

#include "CAFont.h"
#include <memory>

NS_CC_BEGIN

class CAFontProcesstor
{
public:
    
    static std::unique_ptr<CABitmapData> imageForText(const std::string& text, CAFont& font, DSize dimensions, CATextAlignment textHAlignment, CAVerticalTextAlignment textVAlignment);
    
    static float heightForFont(const CAFont& font);
    
    static float heightForTextAtWidth(const std::string& text, const CAFont& font, float width);
    
    static float widthForTextAtOneLine(const std::string& text, const CAFont& font);
};
NS_CC_END
#endif // __CAFontProcesstor_H__

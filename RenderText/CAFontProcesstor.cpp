

#include "CAFontProcesstor.h"
#include "CAFTFontCache.h"
#include "CAFreeTypeFont.h"
#include "CAFTFontCache.h"
NS_CC_BEGIN

std::unique_ptr<CABitmapData> CAFontProcesstor::imageForText(const std::string& text, CAFont& font, DSize dimensions, CATextAlignment textHAlignment, CAVerticalTextAlignment textVAlignment)
{
	return g_AFTFontCache.initWithString(text.c_str(),
		font,
		dimensions.width,
		dimensions.height,
		textHAlignment,
		textVAlignment,
		nullptr);
}

float CAFontProcesstor::heightForFont(const CAFont& font)
{
	return (float)g_AFTFontCache.getFontHeight(font.fontName.c_str(), font.fontSize);
}

float CAFontProcesstor::heightForTextAtWidth(const std::string& text, const CAFont& font, float width)
{
    
	return (float)g_AFTFontCache.getStringHeight(font.fontName.c_str(), font.fontSize, text, width, font.lineSpacing, font.wordWrap);
}

float CAFontProcesstor::widthForTextAtOneLine(const std::string& text, const CAFont& font)
{
    
	return (float)g_AFTFontCache.getStringWidth(font.fontName.c_str(), font.fontSize, text);
}
NS_CC_END

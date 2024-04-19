// RenderText.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "windows.h"

#include "CAFontProcesstor.h"
#include "CAFont.h"
#include "ccUTF8.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <chrono>

int main()
{
    auto text = cc::unicode_to_utf8(L"简体中文\n繁體中文\nBahasa Indonesia\nTiếng Việt\nဗမာစာ\nहिन्दी\n한국어\nEspañol\nPortuguês\ndansk\n日本語\nFrançais\nภาษาไทย\nবেঙ্গল");
    //auto text = cc::unicode_to_utf8(L"简体中文");

    for (int i = 0; i < 100; ++i)
    {
        text.append(cc::unicode_to_utf8(L"中文aaaaaa"));
    }

    cc::CAFont font;
    font.fontName = "simhei";
    // 加粗
    font.bold = true;
    // 中横线
    font.deleteLine = true;
    // 下划线
    font.underLine = true;
    // 倾斜
    font.italics = true;
    font.wordWrap = true;
    font.color = CAColor4B(100, 100, 255, 100);

    //font.shadow.shadowEnabled = true;
    //font.shadow.shadowBlur = 0.0f;
    //font.shadow.shadowOffset = DSize(-6.0f, -6.0f);
    //font.shadow.shadowColor = CAColor4B(255, 0, 0, 255);

    //font.stroke.strokeEnabled = true;
    //font.stroke.strokeSize = 4;
    //font.stroke.strokeColor = CAColor4B(0, 255, 0, 255);
    auto start_time = std::chrono::high_resolution_clock::now();

    auto imageData = cc::CAFontProcesstor::imageForText(text, font, DSize(200.0f, 0.0f), cc::CATextAlignment::Center, cc::CAVerticalTextAlignment::Bottom);

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "Function execution time: " << duration.count() << " milliseconds" << std::endl;


    if (imageData && imageData->len > 0)
    {
        stbi_write_png("out.png", imageData->width, imageData->height, 4, imageData->data, imageData->width * 4);
        free(imageData->data);
        printf("render success\n");
    }
    else
    {
        printf("render failed\n");
    }
    system("pause");
}

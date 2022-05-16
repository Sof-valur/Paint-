#ifndef IMAGE_H
#define IMAGE_H
#include <vector>
#pragma once

struct Color{
  float r,g,b;

   Color();
   Color(float r,float g, float b);
   ~Color();
};


class Image
{
public:
    Image(int wide, int height);
    ~Image();

    Color GetColor(int x, int y) const;
    void SetColor(const Color& color, int x, int y);

    void Read(const char* path);
    void Export(const char* path) const;

private:
    int m_width;
    int m_height;
    std::vector<Color> m_colors;
};

#endif // IMAGE_H

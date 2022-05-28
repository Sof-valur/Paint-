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
    Image();
    ~Image();

    bool empty();

    Color GetColor(int x, int y) const;
    void SetColor(const Color& color, int x, int y);

    void Read(const char* path);
    void Export(const char* path) const;

    int width() const;

    int height() const;

    const std::vector<Color> &colors() const;
    void setColors(const std::vector<Color> &newColors);


private:
    int m_width;
    int m_height;
    std::vector<Color> m_colors;
};

#endif // IMAGE_H

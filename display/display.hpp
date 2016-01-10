#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include "stdlib.h"
#include "stdint.h"
#include <utility>
#include "../drawable/drawable.hpp"
#include "../drawable/Point2D.hpp"

class Display {
public:
  Display(unsigned long *bufferLocation, size_t height, size_t width);
  bool setPixel(size_t x, size_t y);
  size_t height(){return m_height;}
  size_t width(){return m_width;}
  static void clear();
  void drawFrame();
  void draw(const Graphics::Drawable& object, const Graphics::Point2D<size_t>& origin);
private:
  bool pixelInRange(size_t x, size_t y);

  static const size_t maxHeight = 128;
  static const size_t maxWidth = 240;
  unsigned long *m_bufferLocation;
  size_t m_height;
  size_t m_width;
};

#endif /* DISPLAY_HPP_ */

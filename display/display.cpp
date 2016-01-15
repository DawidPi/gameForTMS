#include "display.hpp"
#include "../Logger/Logger.h"
#define SetPixel(Pointer, x, y)                                                \
  Pointer[(x >> 5) + (y << 3)] |= (unsigned long)0x80000000 >> (x & 0x1f)

extern unsigned short int *textEkran;
extern unsigned long *ekran;

Display::Display(unsigned long *bufferLocation, size_t height, size_t width)
    : m_bufferLocation(bufferLocation), m_height(height), m_width(width) {
	LOG_INFO("");
  drawFrame();
}

bool Display::setPixel(size_t x, size_t y) {
	LOG_INFO("");
  if (pixelInRange(x, m_height - y - 1)) {
    SetPixel(m_bufferLocation, x, (m_height - y - 1));
    return true;
  }

  return false;
}

bool Display::pixelInRange(size_t x, size_t y) {
  if (x < m_width && y < m_height)
    return true;

  LOG_ERROR("Pixel out of range: x=" << x << " y=" << y);
  return false;
}

void Display::drawFrame() {
  for (size_t currentWidth = 0; currentWidth < m_width; ++currentWidth) {
    for (size_t currentHeight = 0; currentHeight < m_height; ++currentHeight) {
      if (currentWidth == 0 || currentWidth == m_width - 1 ||
          currentHeight == 0 || currentHeight == m_height - 1) {
        setPixel(currentWidth, currentHeight);
      }
    }
  }
}

void Display::clear(){
	LOG_INFO("");
	  size_t a;
	  for (a = 0; a < (40 * 16); a++)
	    textEkran[a] = ' ';
	  for (a = 0; a < (128 * 8); a++)
	    ekran[a] = 0;
}

void Display::draw(const Graphics::Drawable& object, const Graphics::Point2D<size_t>& origin){
	LOG_INFO("");
	for(size_t currentX =0; currentX < object.width(); ++currentX){
		for(size_t currentY=0; currentY < object.height(); ++currentY){
			Graphics::Point2D<size_t> currentPoint(currentX, currentY);
			if(object.at(currentPoint)){
				setPixel(currentX+origin.width(), currentY + origin.height());
			}
		}
	}
}

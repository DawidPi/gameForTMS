/*
 * SimpleBullet.cpp
 *
 *  Created on: 2 sty 2016
 *      Author: dpilarsk
 */

#include "SimpleBullet.hpp"

namespace Graphics {

SimpleBullet::SimpleBullet() : m_simpleBulletGraphics(true) {
}

size_t SimpleBullet::width() const{
	return m_simpleBulletGraphics.width();
}

size_t SimpleBullet::height() const{
	return m_simpleBulletGraphics.height();
}

bool SimpleBullet::at(Point2D<size_t> point) const{
	return m_simpleBulletGraphics[point.width()][point.height()];
}

} /* namespace Graphics */

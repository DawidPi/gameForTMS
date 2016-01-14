/*
 * SimpleBullet.cpp
 *
 *  Created on: 2 sty 2016
 *      Author: dpilarsk
 */

#include "SimpleBullet.hpp"

namespace Graphics {

SimpleBullet::SimpleBullet() : m_simpleBulletGraphics(true) {
	LOG_INFO("");
}

size_t SimpleBullet::width() const{
	LOG_INFO("");
	return m_simpleBulletGraphics.width();
}

size_t SimpleBullet::height() const{
	LOG_INFO("");
	return m_simpleBulletGraphics.height();
}

bool SimpleBullet::at(Point2D<size_t> point) const{
	LOG_INFO("");
	return m_simpleBulletGraphics[point.width()][point.height()];
}

} /* namespace Graphics */

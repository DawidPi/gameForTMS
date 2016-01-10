/*
 * Enemy.h
 *
 *  Created on: 31 gru 2015
 *      Author: dpilarsk
 */

#ifndef SRC_DRAWABLE_ENEMY_HPP_
#define SRC_DRAWABLE_ENEMY_HPP_

#include "drawable.hpp"
#include "../containers/Array2D.hpp"

namespace Graphics {

class Enemy: public Drawable {
public:
	Enemy();
	virtual size_t width() const;
	virtual size_t height() const;
	virtual bool at(Point2D<size_t> point) const;
	virtual ~Enemy(){};

private:
	Containers::Array2D<bool, 16, 16> m_enemyGraphics;
};

} /* namespace Graphics */

#endif /* SRC_DRAWABLE_ENEMY_HPP_ */

/*
 * SimpleBullet.hpp
 *
 *  Created on: 2 sty 2016
 *      Author: dpilarsk
 */

#ifndef SRC_DRAWABLE_SIMPLEBULLET_HPP_
#define SRC_DRAWABLE_SIMPLEBULLET_HPP_

#include "drawable.hpp"
#include "../containers/Array2D.hpp"

namespace Graphics {

class SimpleBullet: public Drawable {
public:
	SimpleBullet();

	virtual size_t width() const;
	virtual size_t height() const;
	virtual bool at(Point2D<size_t> point) const;
	virtual ~SimpleBullet(){};

private:
	Containers::Array2D<bool, 1, 5> m_simpleBulletGraphics;
};

} /* namespace Graphics */

#endif /* SRC_DRAWABLE_SIMPLEBULLET_HPP_ */

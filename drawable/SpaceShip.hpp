/*
 * SpaceShip.h
 *
 *  Created on: 26 gru 2015
 *      Author: dpilarsk
 */

#ifndef SRC_DRAWABLE_SPACESHIP_HPP_
#define SRC_DRAWABLE_SPACESHIP_HPP_

#include "drawable.hpp"
#include "../containers/Array2D.hpp"

namespace Graphics {

	class SpaceShip: public Drawable {
	public:
		SpaceShip();
		virtual size_t width() const;
		virtual size_t height() const;
		virtual bool at(Point2D<size_t> point) const;
	private:
		Containers::Array2D<bool, 15, 15> m_spaceShipGraphics;
	};

} /* namespace Graphics */

#endif /* SRC_DRAWABLE_SPACESHIP_HPP_ */

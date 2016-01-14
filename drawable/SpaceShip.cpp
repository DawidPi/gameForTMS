/*
 * SpaceShip.cpp
 *
 *  Created on: 26 gru 2015
 *      Author: dpilarsk
 */

#include "SpaceShip.hpp"

namespace Graphics {

SpaceShip::SpaceShip() : m_spaceShipGraphics(static_cast<bool>(0)) {
	LOG_INFO("");
	bool spaceShipTmp[15][15] = {
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},
			{0,1,1,0,0,1,0,0,0,1,0,0,1,1,0},
			{0,0,1,0,0,1,1,1,1,1,0,0,1,0,0},
			{0,1,1,1,1,1,0,0,0,1,1,1,1,1,0},
			{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0},
			{0,0,1,0,0,1,0,0,0,1,0,0,1,0,0},
			{0,0,0,1,0,1,0,0,0,1,0,1,0,0,0},
			{0,0,0,0,1,1,0,0,0,1,1,0,0,0,0},
			{0,0,0,0,0,1,0,1,0,1,0,0,0,0,0},
			{0,0,0,0,1,1,0,1,0,1,1,0,0,0,0},
			{0,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
			{0,0,0,0,1,0,0,1,0,0,1,0,0,0,0},
			{0,0,0,0,1,0,0,1,0,0,1,0,0,0,0}
	};

	for(size_t currentX=0; currentX < 15; ++currentX){
		for(size_t currentY=0; currentY < 15; ++currentY){
			m_spaceShipGraphics[currentY][14-currentX] = spaceShipTmp[currentX][currentY];
		}
	}
}

size_t SpaceShip::width() const{
	LOG_INFO("");
	return m_spaceShipGraphics.width();
}

size_t SpaceShip::height() const{
	LOG_INFO("");
	return m_spaceShipGraphics.height();
}

bool SpaceShip::at(Point2D<size_t> point) const{
	LOG_INFO("");
	return m_spaceShipGraphics[point.width()][point.height()];
}

} /* namespace Graphics */

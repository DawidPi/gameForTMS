/*
 * Enemy.cpp
 *
 *  Created on: 31 gru 2015
 *      Author: dpilarsk
 */

#include "Enemy.hpp"

namespace Graphics {

Enemy::Enemy() {
	bool enemyTmpShape[16][16]={
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0},
			{0,0,0,1,0,1,1,1,1,1,1,0,1,0,0,0},
			{0,0,0,1,0,1,1,1,1,1,1,0,1,0,0,0},
			{0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
			{0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
			{0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
			{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
			{0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
			{0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
			{0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
			{0,0,0,1,0,1,1,1,1,1,1,0,1,0,0,0},
			{0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0},
			{0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};

	for(size_t currentX=0; currentX < 16; ++currentX){
		for(size_t currentY=0; currentY < 16; ++currentY){
			m_enemyGraphics[currentY][15-currentX] = enemyTmpShape[currentX][currentY];
		}
	}
}

size_t Enemy::width() const{
	return m_enemyGraphics.width();
}

size_t Enemy::height() const {
	return m_enemyGraphics.height();
}

bool Enemy::at(Point2D<size_t> point) const{
	return m_enemyGraphics[point.width()][point.height()];
}

} /* namespace Graphics */

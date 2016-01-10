
#include "EnemyGroup.hpp"

namespace Graphics {

EnemyGroup::EnemyGroup() : m_enemiesOn(true) {}

void EnemyGroup::destroyEnemy(size_t column, size_t row){
	m_enemiesOn[column][row] = false;
}

void EnemyGroup::resurrectEnemy(size_t column, size_t row){
	m_enemiesOn[column][row] = true;
}

size_t EnemyGroup::width() const{
	return m_enemyGraphics.width() * m_enemiesOn.width();
}

size_t EnemyGroup::height() const{
	return m_enemyGraphics.height() * m_enemiesOn.height();
}

bool EnemyGroup::at(Point2D<size_t> point) const{
	size_t enemyCol = point.width()/m_enemyGraphics.width();
	size_t enemyRow = point.height()/m_enemyGraphics.height();

	if(m_enemiesOn[enemyCol][enemyRow]){
		size_t effectiveX = point.width()%m_enemyGraphics.width();
		size_t effectiveY = point.height()%m_enemyGraphics.height();
		return m_enemyGraphics.at(Point2D<size_t>(effectiveX, effectiveY));
	}
	else
		return false;
}

} /* namespace Graphics */

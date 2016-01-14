#include "Enemy.hpp"
#include "GameObjectsManager.hpp"

namespace Game {

Enemy::Enemy(GameObjectsManager* parent, Graphics::Point2D<size_t> startPoint) :
	GameObject(parent), m_moveDirection(RIGHT), m_movedSteps(0){
	LOG_INFO("");
	position().setHeight(startPoint.height());
	position().setWidth(startPoint.width());
}

const Graphics::Drawable& Enemy::graphics() const{
	LOG_INFO("");
	return m_enemyGraphics;
}

void Enemy::onCollision(const GameObject& ){
	LOG_INFO("");
	destroy();
}

void Enemy::onButtonPressed(size_t){LOG_INFO("");}

void Enemy::destroy(){
	LOG_INFO("");
	parent().deleteEnemy(this);
}

void Enemy::onStepPassed(){
	LOG_INFO("");
	if(LEFT == m_moveDirection)
		moveLeft();
	else
		moveRight();
}

void Enemy::moveRight(){
	LOG_INFO("");
	int movePixels=1;
	move(std::pair<int,int>(movePixels,0));
	m_movedSteps += movePixels;

	if(m_movedSteps > graphics().width()*1.5)
		m_moveDirection = LEFT;
}

void Enemy::moveLeft(){
	LOG_INFO("");
	int movePixels=-1;
	move(std::pair<int,int>(movePixels,0));
	m_movedSteps += movePixels;

	if(-m_movedSteps > graphics().width()*1.5)
		m_moveDirection = RIGHT;
}

} /* namespace Game */

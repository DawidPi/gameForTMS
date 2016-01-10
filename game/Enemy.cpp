#include "Enemy.hpp"
#include "GameObjectsManager.hpp"

namespace Game {

Enemy::Enemy(GameObjectsManager* parent, Graphics::Point2D<size_t> startPoint) :
	GameObject(parent), m_moveDirection(RIGHT), m_movedSteps(0){
	position().setHeight(startPoint.height());
	position().setWidth(startPoint.width());
}

const Graphics::Drawable& Enemy::graphics() const{
	return m_enemyGraphics;
}

void Enemy::onCollision(const GameObject& ){
	destroy();
}

void Enemy::onButtonPressed(size_t){}

void Enemy::destroy(){
	parent().deleteEnemy(this);
}

void Enemy::onStepPassed(){
	if(LEFT == m_moveDirection)
		moveLeft();
	else
		moveRight();
}

void Enemy::moveRight(){
	int movePixels=1;
	move(std::pair<int,int>(movePixels,0));
	m_movedSteps += movePixels;

	if(m_movedSteps > graphics().width()*1.5)
		m_moveDirection = LEFT;
}

void Enemy::moveLeft(){
	int movePixels=-1;
	move(std::pair<int,int>(movePixels,0));
	m_movedSteps += movePixels;

	if(-m_movedSteps > graphics().width()*1.5)
		m_moveDirection = RIGHT;
}

} /* namespace Game */

/*
 * Bullet.cpp
 *
 *  Created on: 15 sty 2016
 *      Author: dpilarsk
 */

#include "Bullet.hpp"
#include "GameObjectsManager.hpp"

namespace Game {

const Graphics::SimpleBullet Bullet::m_bulletShape;
Bullet::Bullet(GameObjectsManager* parent,
			Graphics::Point2D<size_t> startPoint)
			: GameObject(parent){
	if(parent)
	//	parent->registerBullet(this);
	position() = startPoint;
}

void Bullet::onCollision(const GameObject& collideObject){
	parent().deleteBullet(this);
}

void Bullet::onStepPassed(){
	position().setHeight(position().height() +1);
}

const Graphics::Drawable& Bullet::graphics() const {
	return m_bulletShape;
}

void Bullet::destroy(){
	parent().deleteBullet(this);
}

Bullet::~Bullet() {
	// TODO Auto-generated destructor stub
}

} /* namespace Game */

/*
 * Bullet.hpp
 *
 *  Created on: 15 sty 2016
 *      Author: dpilarsk
 */

#ifndef SRC_GAME_BULLET_HPP_
#define SRC_GAME_BULLET_HPP_

#include "GameObject.hpp"
#include "../drawable/SimpleBullet.hpp"

namespace Game {

class Bullet: public GameObject {
public:
	Bullet(GameObjectsManager* parent, Graphics::Point2D<size_t> startPoint = Graphics::Point2D<size_t>());
	virtual void onCollision(const GameObject& collideObject);
	virtual void onStepPassed();
	virtual void onButtonPressed(size_t keyNumber){}
	virtual const Graphics::Drawable& graphics() const;
	virtual void destroy();

	virtual ~Bullet();
private:
	static const Graphics::SimpleBullet m_bulletShape;
};

} /* namespace Game */

#endif /* SRC_GAME_BULLET_HPP_ */

/*
 * Enemy.hpp
 *
 *  Created on: 3 sty 2016
 *      Author: dpilarsk
 */

#ifndef SRC_GAME_ENEMY_HPP_
#define SRC_GAME_ENEMY_HPP_

#include "GameObject.hpp"
#include "../drawable/Enemy.hpp"

namespace Game {

class Enemy: public GameObject {
public:
	Enemy(GameObjectsManager* parent, Graphics::Point2D<size_t> startPoint = Graphics::Point2D<size_t>());
	virtual void onCollision(const GameObject&);
	virtual void onStepPassed();
	virtual const Graphics::Drawable& graphics() const;
	virtual void destroy();
	virtual void onButtonPressed(size_t keyNumber);
	virtual ~Enemy(){};

private:
	enum Direction{LEFT, RIGHT};
	void moveRight();
	void moveLeft();
	static const Graphics::Enemy m_enemyGraphics;
	Direction m_moveDirection;
	int m_movedSteps;
};

} /* namespace Game */

#endif /* SRC_GAME_ENEMY_HPP_ */

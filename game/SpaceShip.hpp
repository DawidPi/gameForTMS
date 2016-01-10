
#ifndef SRC_GAME_SPACESHIP_HPP_
#define SRC_GAME_SPACESHIP_HPP_

#include "../drawable/SpaceShip.hpp"
#include "../drawable/Point2D.hpp"
#include "../display/display.hpp"
#include "GameObject.hpp"

namespace Game {

class SpaceShip : public GameObject{
public:
	SpaceShip(GameObjectsManager* parent);
	virtual void onButtonPressed(size_t keyNumber);
	virtual void onCollision(const GameObject&);
	virtual void onStepPassed(){};
	virtual void destroy();
	virtual const Graphics::Drawable& graphics() const;

	virtual ~SpaceShip(){};
private:
	void moveLeft();
	void moveRight();
	Graphics::SpaceShip m_spaceShipShape;
};

} /* namespace Game */

#endif /* SRC_GAME_SPACESHIP_HPP_ */

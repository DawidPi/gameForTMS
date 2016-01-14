#include "SpaceShip.hpp"
#include "GameObjectsManager.hpp"

namespace Game {

SpaceShip::SpaceShip(GameObjectsManager* parent) : GameObject(parent){
	LOG_INFO("");
	const size_t maxWidth = parent->display().width();
	position().setWidth(maxWidth/2 - graphics().width()/2);
}

void SpaceShip::onButtonPressed(size_t keyNumber){
	LOG_INFO("");
	switch(keyNumber){
	case 4:
		moveLeft();
		break;
	case 6:
		moveRight();
		break;
	}
}

void SpaceShip::moveLeft(){
	LOG_INFO("");
	const size_t currentWidth = position().width();
	if(currentWidth > 2)
		position().setWidth(currentWidth - 2);
}

void SpaceShip::moveRight(){
	LOG_INFO("");
	const size_t maxWidth = parent().display().width();
	const size_t currentWidth = position().width();

	if(currentWidth < maxWidth - 2)
		position().setWidth(currentWidth + 2);
}

void SpaceShip::destroy(){
	LOG_INFO("");
	parent().deleteShip(this);
}

void SpaceShip::onCollision(const GameObject&){
	LOG_INFO("");
	// TODO : do gameOver stuff
}

const Graphics::Drawable& SpaceShip::graphics() const{
	LOG_INFO("");
	return m_spaceShipShape;
}

} /* namespace Game */

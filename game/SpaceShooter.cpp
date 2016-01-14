#include "SpaceShooter.hpp"
#include "SpaceShip.hpp"
#include "../Logger/Logger.h"

extern int (*PartialRefresh)();

namespace Game {


void SpaceShooter::start(){
	LOG_INFO("");
	LOG_INFO("Check");
	GameObjectsManager objectsManager(m_display);
	LOG_INFO("Objects ManagerCreated");
	Containers::Array2D<Enemy, 6, 2> enemies(&objectsManager);
	initEnemies(enemies, objectsManager);
	SpaceShip spaceShip(&objectsManager);

	LOG_INFO("Game elements created");

	while(1){
		m_display.clear();
		m_display.drawFrame();
		LOG_INFO("Frame drawn");


		objectsManager.doStep(m_keyboard);
		LOG_INFO("single Step executed");

		drawObjectsFromContainer(objectsManager.getAllObjects());
		LOG_INFO("Objects drawn");

		m_lcd.Synchronize();

#ifdef TMSLAB_WIN
    if (PartialRefresh())
    	return;
#endif

    	LOG_INFO("Next iteration");
	}

}

void SpaceShooter::initEnemies(Containers::Array2D<Enemy,6, 2>& enemies,
		GameObjectsManager& manager){
	LOG_INFO("");

	size_t maxHeight = manager.display().height();

	for(size_t currentWidth=0; currentWidth < 6; ++currentWidth){
		for(size_t currentHeight=0; currentHeight < 2; ++currentHeight){
			size_t height = maxHeight - Graphics::Enemy().height()*currentHeight;
			size_t width = currentWidth*Graphics::Enemy().width();
			enemies[currentWidth][currentHeight].position() =
					Graphics::Point2D<size_t>(width,height);

			manager.registerEnemy(&enemies[currentWidth][currentHeight]);
		}
	}

	LOG_INFO("Enemies initiated");
}
} /* namespace Game */

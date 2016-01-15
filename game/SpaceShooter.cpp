#include "SpaceShooter.hpp"
#include "SpaceShip.hpp"
#include "../Logger/Logger.h"
#define TMSLAB_WIN

extern int (*PartialRefresh)();

namespace Game {


void SpaceShooter::start(){
	LOG_INFO("");
	LOG_INFO("Check");
	GameObjectsManager objectsManager(m_display);
	LOG_INFO("Objects ManagerCreated");
	Containers::Array2D<Enemy, 11, 2> enemies(&objectsManager);
	LOG_INFO("Enemies created");
	initEnemies(enemies, objectsManager);
	LOG_INFO("Enemies' poses set");
	SpaceShip spaceShip(&objectsManager);
	LOG_INFO("Space ship created");

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

void SpaceShooter::initEnemies(Containers::Array2D<Enemy,11, 2>& enemies,
		GameObjectsManager& manager){
	size_t maxHeight = manager.display().height();

	for(size_t currentWidth=0; currentWidth < enemies.width(); ++currentWidth){
		for(size_t currentHeight=0; currentHeight < enemies.height(); ++currentHeight){
			size_t height = maxHeight - Graphics::Enemy().height()*(currentHeight+1);
			size_t width = (currentWidth+2)*Graphics::Enemy().width();
			enemies[currentWidth][currentHeight].position() =
					Graphics::Point2D<size_t>(width,height);

			manager.registerEnemy(&enemies[currentWidth][currentHeight]);
		}
	}

	LOG_INFO("Enemies initiated");
}
} /* namespace Game */

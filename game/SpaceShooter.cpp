#include "SpaceShooter.hpp"
#include "SpaceShip.hpp"

extern int (*PartialRefresh)();

namespace Game {


void SpaceShooter::start(){

	GameObjectsManager objectsManager(m_display);
	Containers::Array2D<Enemy, 6, 2> enemies(objectsManager);
	initEnemies(enemies, objectsManager);
	SpaceShip spaceShip(objectsManager);

	while(1){
		m_display.clear();
		m_display.drawFrame();

		objectsManager.doStep(m_keyboard);
		drawObjectsFromContainer(objectsManager.getAllObjects());
		m_lcd.Synchronize();

#ifdef TMSLAB_WIN
    if (PartialRefresh())
    	return;
#endif
	}

}

void SpaceShooter::initEnemies(Containers::Array2D<Enemy,6, 2>& enemies,
		GameObjectsManager& manager){
	size_t maxHeight = manager.display().height();

	for(size_t currentWidth=0; currentWidth < 6; ++currentWidth){
		for(size_t currentHeight=0; currentHeight < 2; ++currentHeight){

			size_t height = maxHeight - Graphics::Enemy().height()*currentHeight;
			size_t width = currentWidth*Graphics::Enemy().width();
			enemies[currentWidth][currentHeight] =
					Enemy(manager, Graphics::Point2D<size_t>(width,height));

			manager.registerEnemy(&enemies[currentWidth][currentHeight]);
		}
	}
}
} /* namespace Game */

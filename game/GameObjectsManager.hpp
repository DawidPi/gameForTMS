#ifndef SRC_GAME_GAMEOBJECTSMANAGER_HPP_
#define SRC_GAME_GAMEOBJECTSMANAGER_HPP_

#include "../containers/Array1D.hpp"
#include "../R_P_KEYBOARD_TMSLAB.h"
#include "SpaceShip.hpp"
#include "../display/display.hpp"

namespace Game {
	class GameObject;
class GameObjectsManager {
public:
	GameObjectsManager(Display& display);
	void doStep(R_P_KEYBOARD_TMSLAB& keyboard);
	bool registerEnemy(GameObject* enemy);
	bool registerBullet(GameObject* bullet);
	bool registerShip(GameObject* spaceShip);
	void deleteEnemy(GameObject* enemy);
	void deleteBullet(GameObject* bullet);
	void deleteShip(GameObject* spaceShip);

	Containers::Array1D<GameObject*, 22>& getEnemies();
	Containers::Array1D<GameObject*, 10>& getBullets();
	Containers::Array1D<GameObject*, 36>& getAllObjects();
	GameObject* getSpaceShip();

	Display& display();

private:
	void deleteObject(GameObject* gameObject);
	bool registerObject(GameObject* gameObject);
	template <size_t sizeOfContainer>
	bool insert(GameObject* object, Containers::Array1D<GameObject*, sizeOfContainer>& container);
	GameObject* m_registeredShip;
	Containers::Array1D<GameObject*, 36> m_allObjects;
	Containers::Array1D<GameObject*, 10> m_bullets;
	Containers::Array1D<GameObject*, 22> m_enemies;
	Display& m_display;
};

template <size_t sizeOfContainer>
bool GameObjectsManager::insert(GameObject* object, Containers::Array1D<GameObject*,
		sizeOfContainer>& container){
	if(object == 0)
		return false;

	for(size_t currentObjIdx=0; currentObjIdx < sizeOfContainer;
			++currentObjIdx){
		if(container[currentObjIdx] == 0){
			container[currentObjIdx] = object;
			return true;
		}
	}

	return false;
}

} /* namespace Game */

#endif /* SRC_GAME_GAMEOBJECTSMANAGER_HPP_ */

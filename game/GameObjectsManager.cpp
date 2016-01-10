#include "GameObjectsManager.hpp"
#include "GameObject.hpp"
#include "KeyboardEventManager.hpp"
#include "CollisionDetector.hpp"


namespace Game {

	GameObjectsManager::GameObjectsManager(Display& display) :
		m_registeredShip(0), m_allObjects(0),
		m_bullets(0), m_enemies(0),
			m_display(display){
	}

	void GameObjectsManager::doStep(R_P_KEYBOARD_TMSLAB& keyboard){
		KeyboardEventManager().detectAndPropagate(keyboard, m_allObjects);
		CollisionDetector().detectAndPropagate(m_bullets,m_allObjects);

		for(size_t currentObjectIdx=0; currentObjectIdx < m_allObjects.size();
				++currentObjectIdx){
			if(m_allObjects[currentObjectIdx] == static_cast<void*>(0))
				continue;

			m_allObjects[currentObjectIdx]->onStepPassed();
		}
	}

	bool GameObjectsManager::registerEnemy(GameObject* enemy){
		bool result = true;
		result &= registerObject(enemy);
		result &= insert(enemy, m_enemies);
		return result;
	}

	bool GameObjectsManager::registerBullet(GameObject* bullet){
		bool result = true;
		result &= registerObject(bullet);
		result &= insert(bullet, m_bullets);
		return result;
	}

	bool GameObjectsManager::registerShip(GameObject* spaceShip){
		if(0 == m_registeredShip)
			return false;

		m_registeredShip = spaceShip;
		bool successful = registerObject(spaceShip);
		return successful;
	}

	bool GameObjectsManager::registerObject(GameObject* gameObject){
		return insert(gameObject, m_allObjects);
	}

	Display& GameObjectsManager::display(){
		return m_display;
	}

	void GameObjectsManager::deleteBullet(GameObject* bullet){
		for(size_t currentObjIdx=0; currentObjIdx < m_bullets.size();
				++currentObjIdx){
			if(bullet == m_bullets[currentObjIdx])
				m_bullets[currentObjIdx] = 0;
		}
	}

	void GameObjectsManager::deleteEnemy(GameObject* enemy){
		for(size_t currentObjIdx=0; currentObjIdx < m_enemies.size();
			++currentObjIdx){
			if(enemy == m_enemies[currentObjIdx])
				m_enemies[currentObjIdx] = 0;
		}
	}

	void GameObjectsManager::deleteShip(GameObject*){
		m_registeredShip = 0;
	}

	void GameObjectsManager::deleteObject(GameObject* gameObject){
		for(size_t currentObjIdx=0; currentObjIdx < m_allObjects.size();
				++currentObjIdx){
			if(m_allObjects[currentObjIdx] == gameObject)
				m_allObjects[currentObjIdx] = 0;
		}
	}

	Containers::Array1D<GameObject*, 25>& GameObjectsManager::getEnemies(){
		return m_enemies;
	}
	Containers::Array1D<GameObject*, 10>& GameObjectsManager::getBullets(){
		return m_bullets;
	}
	Containers::Array1D<GameObject*, 36>& GameObjectsManager::getAllObjects(){
		return m_allObjects;
	}
	GameObject* GameObjectsManager::getSpaceShip(){
		return m_registeredShip;
	}

} /* namespace Game */

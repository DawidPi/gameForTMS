#include "GameObjectsManager.hpp"
#include "GameObject.hpp"
#include "KeyboardEventManager.hpp"
#include "CollisionDetector.hpp"
#include "../Logger/Logger.h"


namespace Game {

	GameObjectsManager::GameObjectsManager(Display& display) :
		m_registeredShip(0), m_allObjects(0),
		m_bullets(0), m_enemies(0),
			m_display(display){
		LOG_INFO("");
	}

	void GameObjectsManager::doStep(R_P_KEYBOARD_TMSLAB& keyboard){
		LOG_INFO("");
		KeyboardEventManager().detectAndPropagate(keyboard, m_allObjects);
		CollisionDetector().detectAndPropagate(m_bullets,m_allObjects);

		for(size_t currentObjectIdx=0; currentObjectIdx < m_allObjects.size();
				++currentObjectIdx){
			if(static_cast<void*>(0) == m_allObjects[currentObjectIdx] )
				continue;

			LOG_INFO("Element ") << currentObjectIdx << " detected" << Logger::flush;
			m_allObjects[currentObjectIdx]->onStepPassed();
		}
	}

	bool GameObjectsManager::registerEnemy(GameObject* enemy){
		LOG_INFO("Enemy registered");
		bool result = true;
		result &= registerObject(enemy);
		result &= insert(enemy, m_enemies);
		return result;
	}

	bool GameObjectsManager::registerBullet(GameObject* bullet){
		LOG_INFO("");
		bool result = true;
		result &= registerObject(bullet);
		LOG_INFO("register bullet result: " << result);
		result &= insert(bullet, m_bullets);
		LOG_INFO("insert bullet result: " << result);

		if(result)
			LOG_WARN("Registering object failed");

		return result;
	}

	bool GameObjectsManager::registerShip(GameObject* spaceShip){
		LOG_INFO("Ship register");
		if(0 == m_registeredShip){
			LOG_ERROR("Ship register failed - null Ship");
			return false;
		}

		m_registeredShip = spaceShip;
		bool successful = registerObject(spaceShip);

		if(!successful)
			LOG_ERROR("Ship register failed");

		return successful;
	}

	bool GameObjectsManager::registerObject(GameObject* gameObject){
		LOG_INFO("");
		return insert(gameObject, m_allObjects);
	}

	Display& GameObjectsManager::display(){
		LOG_INFO("");
		return m_display;
	}

	void GameObjectsManager::deleteBullet(GameObject* bullet){
		LOG_INFO("");
		for(size_t currentObjIdx=0; currentObjIdx < m_bullets.size();
				++currentObjIdx){
			if(bullet == m_bullets[currentObjIdx])
				m_bullets[currentObjIdx] = 0;
		}
	}

	void GameObjectsManager::deleteEnemy(GameObject* enemy){
		LOG_INFO("");
		for(size_t currentObjIdx=0; currentObjIdx < m_enemies.size();
			++currentObjIdx){
			if(enemy == m_enemies[currentObjIdx])
				m_enemies[currentObjIdx] = 0;
		}
	}

	void GameObjectsManager::deleteShip(GameObject*){
		LOG_INFO("");
		m_registeredShip = 0;
	}

	void GameObjectsManager::deleteObject(GameObject* gameObject){
		LOG_INFO("");
		for(size_t currentObjIdx=0; currentObjIdx < m_allObjects.size();
				++currentObjIdx){
			if(m_allObjects[currentObjIdx] == gameObject)
				m_allObjects[currentObjIdx] = 0;
		}
	}

	Containers::Array1D<GameObject*, 22>& GameObjectsManager::getEnemies(){
		LOG_INFO("");
		return m_enemies;
	}
	Containers::Array1D<GameObject*, 10>& GameObjectsManager::getBullets(){
		LOG_INFO("");
		return m_bullets;
	}
	Containers::Array1D<GameObject*, 36>& GameObjectsManager::getAllObjects(){
		LOG_INFO("");
		return m_allObjects;
	}
	GameObject* GameObjectsManager::getSpaceShip(){
		LOG_INFO("");
		return m_registeredShip;
	}

} /* namespace Game */

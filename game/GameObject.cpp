#include "GameObject.hpp"
#include "GameObjectsManager.hpp"

namespace Game {

GameObject::GameObject(GameObjectsManager* parent) : m_parent(parent),
		m_position(){LOG_INFO("");}

GameObject::GameObject(const GameObject& rhs) : m_parent(const_cast<GameObjectsManager*>(&rhs.parent())),
		m_position(rhs.position()){LOG_INFO("");}

const GameObject& GameObject::operator=(const GameObject& rhs){
	LOG_INFO("");
	m_parent = rhs.m_parent;
	m_position = rhs.m_position;
	return *this;
}

void GameObject::move(std::pair<int,int> xAndY){
	LOG_INFO("");
	m_position.setHeight(m_position.height() + xAndY.second);
	m_position.setWidth(m_position.width() + xAndY.first);
}

GameObjectsManager& GameObject::parent(){
	LOG_INFO("");
	return *m_parent;
}

const GameObjectsManager& GameObject::parent() const {
	LOG_INFO("");
	return *m_parent;
}

} /* namespace Game */

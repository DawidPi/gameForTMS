#include "GameObject.hpp"
#include "GameObjectsManager.hpp"

namespace Game {

GameObject::GameObject(GameObjectsManager* parent) : m_parent(parent),
		m_position(){}

GameObject::GameObject(const GameObject& rhs) : m_parent(const_cast<GameObjectsManager*>(&rhs.parent())),
		m_position(rhs.position()){}

const GameObject& GameObject::operator=(const GameObject& rhs){
	m_parent = rhs.m_parent;
	m_position = rhs.m_position;
	return *this;
}

void GameObject::move(std::pair<int,int> xAndY){
	m_position.setHeight(m_position.height() + xAndY.second);
	m_position.setWidth(m_position.width() + xAndY.first);
}

GameObjectsManager& GameObject::parent(){
	return *m_parent;
}

const GameObjectsManager& GameObject::parent() const {
	return *m_parent;
}

} /* namespace Game */

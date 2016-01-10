#include "GameObject.hpp"
#include "GameObjectsManager.hpp"

namespace Game {

GameObject::GameObject(GameObjectsManager& parent) : m_parent(parent),
		m_position(){}

void GameObject::move(std::pair<int,int> xAndY){
	m_position.setHeight(m_position.height() + xAndY.second);
	m_position.setWidth(m_position.width() + xAndY.first);
}

GameObjectsManager& GameObject::parent(){
	return m_parent;
}

const GameObjectsManager& GameObject::parent() const {
	return m_parent;
}

void GameObject::onButtonPressed(size_t keyNumber){}
void GameObject::onCollision(const GameObject& collideObject){}
void GameObject::onStepPassed(){}

} /* namespace Game */

#ifndef SRC_GAME_GAMEOBJECT_HPP_
#define SRC_GAME_GAMEOBJECT_HPP_

#include "../drawable/drawable.hpp"
#include "../drawable/Point2D.hpp"
#include <utility>

namespace Game {
class GameObjectsManager;
class GameObject {
public:
	GameObject(GameObjectsManager& parent);
	virtual void onButtonPressed(size_t keyNumber)=0;
	virtual void onCollision(const GameObject& collideObject)=0;
	virtual void onStepPassed()=0;
	virtual const Graphics::Drawable& graphics() const =0;
	Graphics::Point2D<size_t>& position(){return m_position;}
	const Graphics::Point2D<size_t>& position() const {return m_position;}
	void move(std::pair<int,int> xAndY);
	GameObjectsManager& parent();
	const GameObjectsManager& parent() const;
	virtual void destroy()=0;

	virtual ~GameObject(){};
private:
	GameObjectsManager& m_parent;
	Graphics::Point2D<size_t> m_position;
};

} /* namespace Game */

#endif /* SRC_GAME_GAMEOBJECT_HPP_ */
